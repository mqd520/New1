#include "stdafx.h"
#include "GameService.h"

GameService::GameService(int nTableId) :
tableDataMgr(nTableId),
gameRoundSrv(nTableId),
gameStatusMgr(nTableId),

nTableId(nTableId)
{

}

void GameService::Init()
{
	tableDataMgr.Init();
	gameRoundSrv.Init();
}

void GameService::Exit()
{
	tableDataMgr.Exit();
	gameRoundSrv.Exit();
}

int GameService::GetTableId()
{
	return nTableId;
}

TableDataMgr* GameService::GetTableDataMgr()
{
	return &tableDataMgr;
}

GameRoundService* GameService::GetGameRoundSrv()
{
	return &gameRoundSrv;
}

GameStatusMgr* GameService::GetGameStatusMgr()
{
	return &gameStatusMgr;
}