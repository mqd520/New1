#include "stdafx.h"
#include "PlazaService.h"
#include "CenterService.h"

#include "pck/IGPacket.h"
using namespace pck;

PlazaService::PlazaService(string ip /*= ""*/, int port /*= 0*/) :
CenterCommonService(ip, port)
{

}

PlazaService::~PlazaService()
{

}

void PlazaService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}

void PlazaService::OnProcessPck(PacketData& pd)
{
	switch ((EPacketCmd)pd.cmd)
	{
	case EPacketCmd::ServerListenEx:
		OnServerListenEx(pd);
		break;
	default:
		__super::OnProcessPck(pd);
		break;
	}
}

void PlazaService::OnServerListenEx(PacketData& pd)
{
	ServerListenExPacket* pPck = (ServerListenExPacket*)pd.pPck;
	if (pPck)
	{
		ServerListenPacket pck;
		pck.bInternal = pPck->bInternal;
		pck.nH5Port = pPck->H5Port;
		pck.nIP = pPck->IP;
		pck.nIP1 = 0;
		pck.nPort = pPck->Port;
		pck.ServerType = pPck->ServerType;
		pck.strConnPwd = pPck->strConnPwd;
		pck.strDomainName = pPck->strIP1;
		pck.nWssPort = pPck->H5Port1;

		pCenterSrv->GetServerListenPacketMgr()->Add(pck, pd.peerIp, pd.peerPort);
		pCenterSrv->GetServerListenPacketMgr()->Send2AllServers();
	}
}