#include "stdafx.h"
#include "WebSocketServer.h"

#include "tc/TcpCommuMgr.h"
#include "tc/Log.h"
using namespace tc;

#include "com/StringTool.h"
using namespace com;

#include "ws/WSProtocolHandle.h"
#include "ws/WSException.h"
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

	__super::OnRecvNewConnection(pEvt);
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
			BYTE* pBuf1 = NULL;

			try
			{
				pBuf1 = pWSHandle->ParsePacket(pEvt->GetRecvBuf(), pEvt->GetBufLen(), &len);
			}
			catch (WSException& e)
			{
				TcpLog::WriteLine(ETcpLogType::Error, true, "Websocket parse packet fail: %s, code: %d, peer: %s:%d",
					e.GetErrorInfo().c_str(), e.GetCode(), pEvt->GetPeerIp().c_str(), pEvt->GetPeerPort());

				CloseClient(pEvt->GetSendRecvSocketId());
			}

			if (pBuf1 && len > 0)
			{
				pEvt->ResetBuf(pBuf1, len);
				__super::OnRecvPeerData(pEvt);
			}

		}
		else
		{
			BYTE buf[1024] = { 0 };
			int len = 0;

			try
			{
				len = pWSHandle->HandShake(pEvt->GetRecvBuf(), pEvt->GetBufLen(), buf, 1024);
			}
			catch (WSException& e)
			{
				TcpLog::WriteLine(ETcpLogType::Error, true, "Websocket handshake fail: %s, code: %d, peer: %s:%d",
					e.GetErrorInfo().c_str(), e.GetCode(), pEvt->GetPeerIp().c_str(), pEvt->GetPeerPort());
			}

			if (len > 0)
			{
				Send(pEvt->GetSendRecvSocketId(), buf, len);
				pWSHandle->HandShakeComplete();

				TcpLog::WriteLine(ETcpLogType::Info, true, "Websocket handshake success: %s:%d",
					pEvt->GetPeerIp().c_str(), pEvt->GetPeerPort());
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

	WSProtocolHandle* pWSHandle = wsHandleMgr.Get(clientId);
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