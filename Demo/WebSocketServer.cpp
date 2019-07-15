#include "stdafx.h"
#include "WebSocketServer.h"

#include "tc/TcpCommuMgr.h"
using namespace tc;

#include "com/StringTool.h"
using namespace com;

#include "ws/WSProtocolHandle.h"
using namespace ws;


WebSocketServer::WebSocketServer(string ip /*= ""*/, int port /*= 0*/) :
TcpServer(ip, port)
{

}

WebSocketServer::~WebSocketServer()
{

}

void WebSocketServer::OnRecvNewConnection(RecvNewConnEvt* pEvt)
{
	wsHandleMgr.Create(pEvt->GetSendRecvSocketId());
}

void WebSocketServer::OnConnDisconnect(ConnDisconnectEvt* pEvt)
{
	wsHandleMgr.Remove(pEvt->GetSendRecvSocketId());

	__super::OnConnDisconnect(pEvt);
}

void WebSocketServer::OnRecvPeerData(RecvPeerDataEvt* pEvt)
{
	WSProtocolHandle* pWSHandle = wsHandleMgr.Get(pEvt->GetSendRecvSocketId());
	if (pWSHandle)
	{
		bool b = pWSHandle->IsHandShakeComplete();
		if (b)
		{
			int len = 0;
			BYTE* pBuf1 = pWSHandle->ParsePacket(pEvt->GetRecvBuf(), pEvt->GetBufLen(), &len);
			if (pBuf1 && len > 0)
			{
				pEvt->ResetBuf(pBuf1, len);
			}


			// custom
			string str = "123456";
			Send(pEvt->GetSendRecvSocketId(), (BYTE*)str.c_str(), str.size());
		}
		else
		{
			BYTE buf[1024] = { 0 };
			int len = pWSHandle->HandShake(pEvt->GetRecvBuf(), pEvt->GetBufLen(), buf, 1024);
			if (len > 0)
			{
				Send(pEvt->GetSendRecvSocketId(), buf, len);
				pWSHandle->HandShakeComplete();
			}
			else
			{
				CloseClient(pEvt->GetSendRecvSocketId());
			}
		}
	}
	else
	{
		CloseClient(pEvt->GetSendRecvSocketId());
	}
}

void WebSocketServer::SendData(SOCKET socket, BYTE* pBuf, int len)
{
	SocketInfoData data = TcpCommu::GetSocketDataMgr()->GetSocketData(socket);
	int clientId = data.socketId;

	WSProtocolHandle* pWSHandle = wsHandleMgr.Get(1);
	if (pWSHandle)
	{
		if (pWSHandle->IsHandShakeComplete())
		{
			int len2 = 0;
			BYTE* pBuf2 = pWSHandle->BuildPacket(wsheader_type::TEXT_FRAME, pBuf, len, false, &len2);
			if (pBuf2 && len2 > 0)
			{
				__super::SendData(socket, pBuf2, len2);
			}
			else
			{
				CloseClient(clientId);
			}
		}
		else
		{
			__super::SendData(socket, pBuf, len);
		}
	}
	else
	{
		CloseClient(clientId);
	}
}

void WebSocketServer::CloseClient(int clientId, bool b /*= true*/)
{
	wsHandleMgr.Remove(clientId);

	__super::CloseClient(clientId, b);
}