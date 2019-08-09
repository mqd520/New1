#include "stdafx.h"
#include "GameService.h"

GameService::GameService(int nTableId) :
tableDataMgr(nTableId),
dealerMgr(nTableId),
gameRoundSrv(nTableId),
gameStatusMgr(nTableId),
gamePro(nTableId),

nTableId(nTableId)
{

}

void GameService::Init()
{
	tableDataMgr.Init();
	dealerMgr.Init();

	gameRoundSrv.AttachGameService(this);
	gameRoundSrv.Init();
	
	gameStatusMgr.Init();

	gamePro.AttachGameService(this);
	gamePro.Init();
}

void GameService::Exit()
{
	tableDataMgr.Exit();
	dealerMgr.Exit();
	gameRoundSrv.Exit();
	gameStatusMgr.Exit();
	gamePro.Exit();
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

GameProcess* GameService::GetGameProcess()
{
	return &gamePro;
}

DealerMgr* GameService::GetDealerMgr()
{
	return &dealerMgr;
}