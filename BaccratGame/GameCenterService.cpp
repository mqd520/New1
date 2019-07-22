#include "stdafx.h"
#include "GameCenterService.h"
#include "BaccratService.h"
#include "Log.h"

#include "pck/IGPacket.h"
using namespace pck;


GameCenterService::GameCenterService(string ip /*= ""*/, int port /*= 0*/) :
IGPacketSrvServer(ip, port, EServerType::Baccrat, true),
pBaccratSrv(NULL)
{

}

GameCenterService::~GameCenterService()
{

}

void GameCenterService::OnRecvNewConnection(RecvNewConnEvt* pEvt)
{
	__super::OnRecvNewConnection(pEvt);
}

void GameCenterService::OnConnDisconnect(ConnDisconnectEvt* pEvt)
{
	__super::OnConnDisconnect(pEvt);
}

bool GameCenterService::OnLoginSrvRequest(PacketData& data)
{
	return __super::OnLoginSrvRequest(data);
}

void GameCenterService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}

void GameCenterService::OnProcessPck(PacketData& pd)
{
	__super::OnProcessPck(pd);
}

void GameCenterService::Init()
{
	if (pBaccratSrv == NULL)
	{
		pBaccratSrv = BaccratService::GetInstance();
	}
}

void GameCenterService::Exit()
{
	__super::Exit();
}

void GameCenterService::CloseClient(int clientId, bool b /* = true */)
{
	__super::CloseClient(clientId, b);
}