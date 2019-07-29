#include "stdafx.h"
#include "GameService.h"

GameService::GameService(int nTableId) :
tableDataMgr(nTableId),
dealerMgr(nTableId),
gameRoundSrv(nTableId),
gameStatusMgr(nTableId),
game(nTableId),

nTableId(nTableId)
{

}

void GameService::Init()
{
	tableDataMgr.Init();
	dealerMgr.Init();
	gameRoundSrv.Init();
	gameStatusMgr.Init();

	game.Init();
	game.AttachGameService(this);
}

void GameService::Exit()
{
	tableDataMgr.Exit();
	dealerMgr.Exit();
	gameRoundSrv.Exit();
	gameStatusMgr.Exit();
	game.Exit();
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
	return &game;
}

DealerMgr* GameService::GetDealerMgr()
{
	return &dealerMgr;
}