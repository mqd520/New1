#include "stdafx.h"

#include "Include/pck/IGPacketSrvServer.h"
#include "Include/pck/PacketCmd.h"
#include "Include/pck/LoginSrvRequestPacket.h"
#include "Include/pck/LoginSrvResultPacket.h"
#include "Include/pck/CommonTool.h"
#include "Include/pck/ServerSession.h"
#include "Include/pck/KeepAlivePacket.h"
#include "Include/pck/PacketSessionMgr.h"
#include "Include/pck/PacketSession.h"

#include "tc/Log.h"

namespace pck
{
	IGPacketSrvServer::IGPacketSrvServer(
		string ip /*= ""*/, int port /*= 0*/,
		EServerType localType /*= EServerType::None*/,
		bool bRecvPwd /*= true*/) :

		TcpServer(ip, port),
		IGPacketSrv(localType),
		bRecvPwd(bRecvPwd),
		nCurClientId(0)
	{
		AttachTcpServiceObj(this);
		SetSessionMgr(new PacketSessionMgr());
	}

	IGPacketSrvServer::~IGPacketSrvServer()
	{

	}

	void IGPacketSrvServer::OnRecvNewConnection(RecvNewConnEvt* pEvt)
	{
		__super::OnRecvNewConnection(pEvt);

		nCurClientId = pEvt->GetSendRecvSocketId();
		serverSessionMgr.CreateSession(nCurClientId, this, bRecvPwd);

		PacketSession* pSession1 = (PacketSession*)pSessionMgr->Get1(pEvt->GetPeerIp(), pEvt->GetPeerPort());
		pSession1->localServerType = localType;
	}

	void IGPacketSrvServer::OnRecvPeerData(RecvPeerDataEvt* pEvt)
	{
		__super::OnRecvPeerData(pEvt);

		nCurClientId = pEvt->GetSendRecvSocketId();

		ServerSession* pSession = serverSessionMgr.GetSession(nCurClientId);
		if (pSession)
		{
			if (pSession->OnRecvPeerData(pEvt))
			{
				IGPacketSrv::ProcessRecvBuf(pEvt->GetRecvBuf(), pEvt->GetBufLen(), nCurClientId);
			}
		}
		else
		{
			TcpLog::WriteLine(ETcpLogType::Warn, "lose session: %s:%d", pEvt->GetPeerIp().c_str(), pEvt->GetPeerPort());
			CloseClient(nCurClientId);
		}
	}

	void IGPacketSrvServer::OnConnDisconnect(ConnDisconnectEvt* pEvt)
	{
		__super::OnConnDisconnect(pEvt);

		peerType = EServerType::None;
		nCurClientId = pEvt->GetSendRecvSocketId();
		serverSessionMgr.CloseSession(nCurClientId);
	}

	void IGPacketSrvServer::PreProcessPck(PacketData& data)
	{
		if (data.cmd == (int)EPacketCmd::LoginSrvRequest)
		{
			bool b = OnLoginSrvRequest(data);
			ProcessLoginSrvResult(data, b);
		}
		else if (data.cmd == (int)EPacketCmd::KeepAlive)
		{
			ServerSession* pSession = serverSessionMgr.GetSession(nCurClientId);
			if (pSession)
			{
				pSession->OnRecvKeepAlive();
			}
		}
		else
		{
			__super::PreProcessPck(data);
		}
	}

	bool IGPacketSrvServer::OnLoginSrvRequest(PacketData& data)
	{
		return true;
	}

	void IGPacketSrvServer::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
	{
		LoginSrvRequestPacket* pPck = (LoginSrvRequestPacket*)data.pPck;

		string ip = TcpServer::GetPeerIp(data.clientId);
		int port = TcpServer::GetPeerPort(data.clientId);
		TcpLog::WriteLine(success ? ETcpLogType::Info : ETcpLogType::Warn, "client login local server %s, addr: %s:%d, type: %s",
			success ? "success" : "fail", ip.c_str(), port, CommonTool::GetServerName((EServerType)pPck->cbCurrentServerType).c_str());

		if (pPck)
		{
			if (success)
			{
				peerType = (EServerType)pPck->cbCurrentServerType;

				ServerSession* pSession = serverSessionMgr.GetSession(nCurClientId);
				if (pSession)
				{
					pSession->OnLoginSrvRequest(data, true);
				}

				PacketSession* pSession1 = (PacketSession*)pSessionMgr->Get1(ip, port);
				pSession1->peerServerType = (EServerType)pPck->cbCurrentServerType;

				SendLoginSrvResultPck(data.clientId);
			}
			else
			{
				CloseClient(data.clientId);
			}
		}
	}

	void IGPacketSrvServer::SendLoginSrvResultPck(int clientId)
	{
		LoginSrvResultPacket pck;
		pck.cbVerifyCode = 1;
		pck.nServerID = 32656;

		SendPck(pck, clientId);
	}

	void IGPacketSrvServer::OnSessionClose(int clientId)
	{
		serverSessionMgr.CloseSession(clientId);
		CloseClient(clientId);
	}

	void IGPacketSrvServer::SendKeepAlive(int clientId /*= 0*/)
	{
		KeepAlivePacket pck;
		pck.cbKeepAlive = 1;

		SendPck(pck, clientId);
	}

	void IGPacketSrvServer::OnMissKeepAlive(int clientId, int count, bool b /*= true*/)
	{
		if (b)
		{
			CloseClient(clientId, true);
		}
	}

	void IGPacketSrvServer::SendPck(Packet& pck, int clientId)
	{
		SendPacket(pck, clientId);
	}

	void IGPacketSrvServer::Exit()
	{
		serverSessionMgr.CloseSession();
		TcpServer::Exit();
		IGPacketSrv::Exit();
	}

	void IGPacketSrvServer::CloseClient(int clientId, bool b /*= true*/)
	{
		peerType = EServerType::None;
		serverSessionMgr.CloseSession(clientId);

		__super::CloseClient(clientId, b);
	}
}