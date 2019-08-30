#include "stdafx.h"
#include "GameService.h"
#include "BaccratService.h"


GameService::GameService(int nTableId) :
pBaccratSrv(nullptr),

tableDataMgr(nTableId),
dealerMgr(nTableId),
gameRoundSrv(nTableId),
gameStatusMgr(nTableId),
gamePro(nTableId),

nTableId(nTableId)
{

}

void GameService::OnLoadTableDataSuccess(TableDataMgr* pTableDataMgr, TableData& table)
{
	
}

void GameService::Init()
{
	pBaccratSrv = BaccratService::GetInstance();

	tableDataMgr.AttachGameService(this);
	tableDataMgr.Init();

	dealerMgr.Init();

	gameRoundSrv.AttachGameService(this);
	gameRoundSrv.Init();
	
	gameStatusMgr.AttachGameService(this);
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

void GameService::SendPck_2_GameCenter()
{
	// send pck
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