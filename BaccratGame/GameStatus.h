#pragma once

#include "game/GameDef.h"
#include "game/CountDown.h"
using namespace game;


// GameStatus
class GameStatus
{
public:
	GameStatus(EGameStatus status, int nTime = 0);

	virtual ~GameStatus();

protected:
	const EGameStatus status;	// game status
	CountDown* pCountdown;		// countdown obj

protected:
	//************************************
	// Method:    Start countdown
	//************************************
	void StartCountdown();

	//************************************
	// Method:    Stop countdown
	//************************************
	void StopCountdown();

	//************************************
	// Method:    Reset countdown
	//************************************
	void ResetCountdown();

	//************************************
	// Method:    Is countdown done
	//************************************
	bool IsCountdownDone();

protected:
	//************************************
	// Method:    Countdown done evt handle
	// Parameter: CountDown* p1
	// Parameter: void* pObj
	//************************************
	void OnCountdownDone(CountDown* p1, void* pObj);

public:
	//************************************
	// Method:    Get current main status
	//************************************
	virtual EGameMainStatus GetCurGameMainStatus();

	//************************************
	// Method:    Get current status
	//************************************
	virtual EGameStatus GetCurGameStatus();

	//************************************
	// Method:    Get next status
	//************************************
	virtual EGameStatus GetNextStatus();

	//************************************
	// Method:    Get last status
	//************************************
	virtual EGameStatus GetLastStatus();

	//************************************
	// Method:    Enter
	//************************************
	virtual void Enter();

	//************************************
	// Method:    Leave
	//************************************
	virtual void Leave();

	//************************************
	// Method:    Is completed
	//************************************
	virtual bool IsCompleted();

	//************************************
	// Method:    Exit
	//************************************
	virtual void Exit();
};