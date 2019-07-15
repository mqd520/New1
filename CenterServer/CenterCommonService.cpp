#include "stdafx.h"
#include "CenterCommonService.h"
#include "CenterService.h"
#include "Log.h"

#include "pck/IGPacket.h"
using namespace pck;

CenterCommonService::CenterCommonService(string ip /*= ""*/, int port /*= 0*/) :
IGPacketSrvServer(ip, port, EServerType::Center, true),
pCenterSrv(NULL)
{

}

CenterCommonService::~CenterCommonService()
{

}

void CenterCommonService::OnRecvNewConnection(RecvNewConnEvt* pEvt)
{
	__super::OnRecvNewConnection(pEvt);
}

void CenterCommonService::OnConnDisconnect(ConnDisconnectEvt* pEvt)
{
	string ip = TcpServer::GetPeerIp(pEvt->GetSendRecvSocketId());
	int port = TcpServer::GetPeerPort(pEvt->GetSendRecvSocketId());

	pCenterSrv->GetServerListenPacketMgr()->Remove(ip, port);

	__super::OnConnDisconnect(pEvt);
}

bool CenterCommonService::OnLoginSrvRequest(PacketData& data)
{
	bool b = __super::OnLoginSrvRequest(data);

	if (b)
	{
		LoginSrvRequestPacket* pPck = (LoginSrvRequestPacket*)data.pPck;
		if (pPck)
		{
			return pPck->cbCurrentServerType == (int)EServerType::Plaza && pPck->cbRequestServerID == 1;
		}
	}

	return false;
}

void CenterCommonService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);

	if (success)
	{
		pCenterSrv->GetServerListenPacketMgr()->Send2AllServers();
	}
}

void CenterCommonService::OnProcessPck(PacketData& pd)
{
	switch ((EPacketCmd)pd.cmd)
	{
	case EPacketCmd::ServerListen:
		OnServerListen(pd);
		break;
	default:
		__super::OnProcessPck(pd);
		break;
	}
}

void CenterCommonService::OnServerListen(PacketData& pd)
{
	ServerListenPacket* pPck = (ServerListenPacket*)pd.pPck;
	if (pPck)
	{
		pCenterSrv->GetServerListenPacketMgr()->Add(*pPck, pd.peerIp, pd.peerPort);
		pCenterSrv->GetServerListenPacketMgr()->Send2AllServers();
	}
}

void CenterCommonService::Init()
{
	if (pCenterSrv == NULL)
	{
		pCenterSrv = CenterService::GetInstance();
	}
}

void CenterCommonService::Exit()
{
	__super::Exit();
}

void CenterCommonService::CloseClient(int clientId, bool b /* = true */)
{
	string ip = TcpServer::GetPeerIp(clientId);
	int port = TcpServer::GetPeerPort(clientId);
	pCenterSrv->GetServerListenPacketMgr()->Remove(ip, port);

	__super::CloseClient(clientId, b);
}

void CenterCommonService::SendPck2AllClients(Packet& pck)
{
	vector<int> vec;
	pSessionMgr->GetAllClientId(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		SendPck(pck, *it);
	}
}