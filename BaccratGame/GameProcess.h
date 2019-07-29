#pragma once

#include "db/ApplyGameRoundSrv.h"
using namespace db;

class GameService;


// Game Process
class GameProcess
{
public:
	GameProcess(int nTableId);

private:
	int nTableId;			// table Id
	GameService* pSrv;		// game service obj
	int nDuplicateId;		// duplicate Id
	bool bNeedChangeXue;	// whether need change xue

private:
	ApplyGameRoundSrv appGameRoundSrv;	// ApplyGameRoundSrv obj

private:
	//************************************
	// Method:    Apply game round
	//************************************
	void ApplyGameRound();

private:
	//************************************
	// Method:    Apply game round complete
	// Parameter: DbService * pSrv
	// Parameter: DbResult * pResult
	//************************************
	void OnApplyGameRoundCpl(DbService* pSrv, DbResult* pResult);

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
	// Method:    Attach game service
	// Parameter: GameService * pSrv
	//************************************
	void AttachGameService(GameService* pSrv);

	//************************************
	// Method:    Get Table Id
	//************************************
	int GetTableId();

	//************************************
	// Method:    Start table
	//************************************
	void StartTable();
};