#pragma once

#include "TableDataMgr.h"
#include "DealerMgr.h"
#include "GameRoundService.h"
#include "GameStatusMgr.h"
#include "GameProcess.h"


class BaccratService;


// Game Service
class GameService
{
public:
	GameService(int nTableId);

private:
	int nTableId;							// table Id
	BaccratService* pBaccratSrv;			// BaccratService pointer
	TableDataMgr tableDataMgr;				// table data mgr obj
	DealerMgr dealerMgr;					// dealer mgr obj 
	GameRoundService gameRoundSrv;			// GameRoundDataService obj
	GameStatusMgr gameStatusMgr;			// game status mgr
	GameProcess gamePro;					// game process

private:
	//************************************
	// Method:    Load table data success evt handle
	// Parameter: TableDataMgr * pTableDataMgr
	// Parameter: TableData & table
	//************************************
	void OnLoadTableDataSuccess(TableDataMgr* pTableDataMgr, TableData& table);

public:
	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();
	
	//************************************
	// Method:    Get table Id
	//************************************
	int GetTableId();

	void SendPck_2_GameCenter();

	//************************************
	// Method:    Get table data mgr obj
	//************************************
	TableDataMgr* GetTableDataMgr();

	//************************************
	// Method:    Get game round data srv obj
	//************************************
	GameRoundService* GetGameRoundSrv();

	//************************************
	// Method:    Get game status mgr obj
	//************************************
	GameStatusMgr* GetGameStatusMgr();

	//************************************
	// Method:    Get game process obj
	//************************************
	GameProcess* GetGameProcess();

	//************************************
	// Method:    Get dealer mgr obj
	//************************************
	DealerMgr* GetDealerMgr();
};