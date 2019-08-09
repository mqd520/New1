#pragma once

#include "db/ApplyGameRoundSrv.h"
using namespace db;

#include "game/GameEvt.h"
using namespace game;

class GameService;


// Game Process
class GameProcess
{
public:
	GameProcess(int nTableId);

private:
	int nTableId;				// table Id
	GameService* pGameSrv;		// game service obj

private:
	ApplyGameRoundSrv appGameRoundSrv;	// ApplyGameRoundSrv obj

private:
	//************************************
	// Method:    Apply game round cpl evt
	// Parameter: pEvt: Game evt
	// Parameter: pObj: attach obj
	//************************************
	void OnApplyGameRoundCpl(GameEvt* pEvt, void* pObj);

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
	int GetTableId() const;

	//************************************
	// Method:    Start table
	//************************************
	void StartTable();
};