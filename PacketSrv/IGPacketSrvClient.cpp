#include "stdafx.h"

#include "Include/pck/IGPacketSrvClient.h"
#include "Include/pck/PacketCmd.h"
#include "Include/pck/IGPacketHead.h"
#include "Include/pck/LoginSrvRequestPacket.h"
#include "Include/pck/CommonTool.h"
#include "Include/pck/PacketTool.h"
#include "Include/pck/IGPacket.h"
#include "pwd.hpp"

#include "tc/Log.h"


namespace pck
{
	IGPacketSrvClient::IGPacketSrvClient(
		string ip /*= ""*/, int port /*= 0*/,
		EServerType localType /*= EServerType::None*/,
		EServerType peerType /*= EServerType::None*/, bool bSendPwd /*= true*/) :

		TcpClient(ip, port),
		IGPacketSrv(localType),
		KeepAliveClient(PCR_KeepAlive_Timespan, PCR_KeepAlive_Timeout, PCR_KeepAlive_MaxMissCount),
		peerType(peerType),
		bSendPwd(bSendPwd)
	{
		IGPacketSrv::AttachTcpServiceObj(this);
		KeepAliveClient::AttachObj(this, NULL);
	}

	IGPacketSrvClient::~IGPacketSrvClient()
	{

	}

	void IGPacketSrvClient::OnConnectSrvCpl(ConnectSrvCplEvt* pEvt)
	{
		TcpClient::OnConnectSrvCpl(pEvt);

		if (pEvt->GetConnectResult())
		{
			SendPwd();
			SendLoginSrvRequestPck();
		}
	}

	void IGPacketSrvClient::OnRecvPeerData(RecvPeerDataEvt* pEvt)
	{
		__super::OnRecvPeerData(pEvt);

		IGPacketSrv::ProcessRecvBuf(pEvt->GetRecvBuf(), pEvt->GetBufLen());
	}

	void IGPacketSrvClient::OnConnDisconnect(ConnDisconnectEvt* pEvt)
	{
		__super::OnConnDisconnect(pEvt);
		CloseKeepAlive();
	}

	void IGPacketSrvClient::PreProcessPck(PacketData& data)
	{
		if (data.cmd == (int)EPacketCmd::LoginSrvResult)
		{
			OnLoginSrvSuccess();
		}
		else if (data.cmd == (int)EPacketCmd::KeepAlive)
		{
			OnKeepAlive();
		}
		else
		{
			__super::PreProcessPck(data);
		}
	}

	void IGPacketSrvClient::SendPwd()
	{
		if (bSendPwd)
		{
			BYTE* pBuf = (BYTE*)PCR_ConnectPwd;
			int len = strlen(PCR_ConnectPwd) + 1;

			Send(pBuf, len);

			TcpLog::WriteLine(ETcpLogType::Info, "send pwd to %s server", CommonTool::GetServerName(peerType).c_str());
		}
	}

	void IGPacketSrvClient::SendLoginSrvRequestPck()
	{
		LoginSrvRequestPacket pck;
		pck.cbCurrentServerType = (BYTE)peerType;
		pck.cbRequestServerID = 1;
		pck.cbKeepAlive = 0;
		pck.nVersion = PCR_Version;
		pck.strGuid = CommonTool::CreateGuid();

		SendPck(pck);

		TcpLog::WriteLine(ETcpLogType::Info, "try to login %s server", CommonTool::GetServerName(peerType).c_str());
	}

	void IGPacketSrvClient::OnLoginSrvSuccess()
	{
		TcpLog::WriteLine(ETcpLogType::Info, "login %s server success", CommonTool::GetServerName(peerType).c_str());
		StartKeepAlive();
	}

	void IGPacketSrvClient::SendKeepAlive(int clientId /*= 0*/)
	{
		KeepAlivePacket pck;
		pck.cbKeepAlive = 0;

		SendPck(pck);

		__super::SendKeepAlive(clientId);
	}

	void IGPacketSrvClient::OnMissKeepAlive(int count, bool b /*= true*/)
	{
		__super::OnMissKeepAlive(count, b);

		if (b)
		{
			Close(true);
		}
	}

	void IGPacketSrvClient::SendPck(Packet& pck)
	{
		SendPacket(pck);
	}

	void IGPacketSrvClient::Exit()
	{
		TcpClient::Exit();
		IGPacketSrv::Exit();
		KeepAliveClient::Exit();
	}

	EServerType IGPacketSrvClient::GetPeerServerType()
	{
		return peerType;
	}
}