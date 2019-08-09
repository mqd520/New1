#pragma once

#include "TableDataMgr.h"
#include "DealerMgr.h"
#include "GameRoundService.h"
#include "GameStatusMgr.h"
#include "GameProcess.h"


// Game Service
class GameService
{
public:
	GameService(int nTableId);

private:
	int nTableId;							// table Id
	TableDataMgr tableDataMgr;				// table data mgr obj
	DealerMgr dealerMgr;					// dealer mgr obj 
	GameRoundService gameRoundSrv;			// GameRoundDataService obj
	GameStatusMgr gameStatusMgr;			// game status mgr
	GameProcess gamePro;					// game process

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