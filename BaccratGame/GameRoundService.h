#pragma once

#include <vector>
using namespace std;

#include "db/ApplyGameRoundSrv.h"
using namespace db;

#include "game/GameDef.h"
#include "game/GameEvtReg.h"
using namespace game;

class GameService;


// Game round service
class GameRoundService : public GameEvtReg
{
public:
	GameRoundService(int nTableId);

private:
	int nTableId;				// table Id
	int nGameRoundId;			// round id
	string strGameRoundNo;		// round no
	int nXue;					// xue
	int nPu;					// pu
	vector<int> vecResults;		// game round result list
	int nDuplicateId;			// duplicate Id
	bool bNeedChangeXue;		// whether need change xue

private:
	GameService* pGameSrv;				// game service obj
	ApplyGameRoundSrv appGameRoundSrv;	// ApplyGameRoundSrv obj

private:
	//************************************
	// Method:    Load history data
	//************************************
	void LoadGameRoundData();

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
	// Method:    Get table Id
	//************************************
	int GetTableId() const;

	//************************************
	// Method:    Get game round Id
	//************************************
	int GetGameRoundId() const;

	//************************************
	// Method:    Get game round No.
	//************************************
	string GetGameRoundNo() const;

	//************************************
	// Method:    Get xue
	//************************************
	int GetXue() const;

	//************************************
	// Method:    Get pu
	//************************************
	int GetPu() const;

	//************************************
	// Method:    Apply new game round
	//************************************
	void ApplyNewRound();

	//************************************
	// Method:    Settle game round
	//************************************
	void SettleGameRound();
};