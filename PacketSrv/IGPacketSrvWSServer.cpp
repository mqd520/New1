#include "stdafx.h"
#include "Include/pck/IGPacketSrvWSServer.h"

#include "tc/TcpCommuMgr.h"
using namespace tc;

namespace pck
{
	IGPacketSrvWSServer::IGPacketSrvWSServer(
		string ip /*= ""*/, int port /*= 0*/,
		EServerType localType /*= EServerType::None*/,
		bool bRecvPwd /*= true*/) :

		IGPacketSrvServer(ip, port, localType, bRecvPwd)
	{
			
	}

	void IGPacketSrvWSServer::OnRecvNewConnection(RecvNewConnEvt* pEvt)
	{
		__super::OnRecvNewConnection(pEvt);

		wsHandleMgr.Create(pEvt->GetSendRecvSocketId());
	}

	void IGPacketSrvWSServer::OnConnDisconnect(ConnDisconnectEvt* pEvt)
	{
		wsHandleMgr.Remove(pEvt->GetSendRecvSocketId());

		__super::OnConnDisconnect(pEvt);
	}

	void IGPacketSrvWSServer::OnRecvPeerData(RecvPeerDataEvt* pEvt)
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

	void IGPacketSrvWSServer::SendData(SOCKET socket, BYTE* pBuf, int len)
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

	void IGPacketSrvWSServer::CloseClient(int clientId, bool b /*= true*/)
	{
		wsHandleMgr.Remove(clientId);

		__super::CloseClient(clientId, b);
	}
}