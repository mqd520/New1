#pragma once

#include "TableDataMgr.h"
#include "GameRoundService.h"


// Game Service
class GameService
{
public:
	GameService(int nTableId);

private:
	int nTableId;							// table Id
	TableDataMgr tableDataMgr;				// table data mgr obj
	GameRoundService gameRoundDataMgr;	// GameRoundDataService obj

private:

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

	TableDataMgr* GetTableDataMgr();

	GameRoundService* GetGameDataRoundDataMgr();
};