#include "stdafx.h"
#include "GameService.h"

GameService::GameService(int nTableId) :
tableDataMgr(nTableId),
gameRoundDataMgr(nTableId),

nTableId(nTableId)
{

}

void GameService::Init()
{
	tableDataMgr.Init();
	gameRoundDataMgr.Init();
}

void GameService::Exit()
{
	tableDataMgr.Exit();
	gameRoundDataMgr.Exit();
}

int GameService::GetTableId()
{
	return nTableId;
}

TableDataMgr* GameService::GetTableDataMgr()
{
	return &tableDataMgr;
}

GameRoundService* GameService::GetGameDataRoundDataMgr()
{
	return &gameRoundDataMgr;
}