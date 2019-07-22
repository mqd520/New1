#include "stdafx.h"
#include "BaccratService.h"


BaccratService* pInstance = NULL;	// the unique BaccratService instance

BaccratService::BaccratService()
{

}

BaccratService* BaccratService::GetInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new BaccratService();
	}

	return pInstance;
}

void BaccratService::Init()
{
	gameCenterSrv.Init();
	gameSrvMgr.Init();
}

void BaccratService::Exit()
{
	gameCenterSrv.Exit();
	gameSrvMgr.Exit();
}

GameCenterService* BaccratService::GetGameCenterSrv()
{
	return &gameCenterSrv;
}

GameServiceMgr* BaccratService::GetGameSrvMgr()
{
	return &gameSrvMgr;
}