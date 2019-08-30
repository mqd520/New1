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
	//************************************
	// Method:    Apply game round success evt
	//************************************
	void OnApplyGameRoundSuccess();

	//************************************
	// Method:    Game status inited evt handle
	//************************************
	void OnGameStatusInited();

	//************************************
	// Method:    Game status changed evt handle
	// Parameter: EGameStatus previous
	// Parameter: EGameStatus current
	//************************************
	void OnGameStatusChanged(EGameStatus previous, EGameStatus current);

public:
	//************************************
	// Method:    Attach game service
	// Parameter: GameService * pSrv
	//************************************
	void AttachGameService(GameService* pSrv);

	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();

	//************************************
	// Method:    Get Table Id
	//************************************
	int GetTableId() const;

	//************************************
	// Method:    Start table
	//************************************
	void StartTable();

	//************************************
	// Method:    Start bet
	//************************************
	void StartBet();

	//************************************
	// Method:    Stop bet
	//************************************
	void StopBet();
};