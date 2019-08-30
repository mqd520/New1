#pragma once

#include <vector>
using namespace std;

#include "game/GameDef.h"
#include "game/CountDown.h"
using namespace game;


class GameStatus;

// CountDown complete evt callback
// GameStatus*:	GameStatus pointer
// int:			countdown duration time
using CountDownCplCallback = std::function < void(GameStatus*, int) > ;


// GameStatus
class GameStatus
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: EGameStatus status
	// Parameter: bool isAutoEnterNext:	whether auto enter next status
	// Parameter: int nTime: total time
	//************************************
	GameStatus(EGameStatus status, bool isAutoEnterNext = false, int nTime = 0);

	virtual ~GameStatus();

protected:
	const EGameStatus status;		// game status
	const int nTime;				// duration time
	const bool bIsAutoEnterNext;	// whether auto enter next status
	bool bIsReady;					// whether ready complete

protected:
	CountDown* pCountdown;		// countdown obj
	vector<CountDownCplCallback> vecFns;	// callback list

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

protected:
	//************************************
	// Method:    Countdown done evt handle
	// Parameter: CountDown* p1
	// Parameter: void* pObj
	//************************************
	void OnCountdownDone(CountDown* pCountDown, void* pObj);

public:
	//************************************
	// Method:    Get current main status
	//************************************
	virtual EGameMainStatus GetCurGameMainStatus() const;

	//************************************
	// Method:    Get current status
	//************************************
	virtual EGameStatus GetCurGameStatus() const;

	//************************************
	// Method:    Get next status
	//************************************
	virtual EGameStatus GetNextStatus() const;

	//************************************
	// Method:    Get last status
	//************************************
	virtual EGameStatus GetLastStatus() const;

	//************************************
	// Method:    Is Ready
	//************************************
	virtual bool IsReady() const;

	//************************************
	// Method:    Enter
	//************************************
	virtual void Enter();

	//************************************
	// Method:    Leave
	//************************************
	virtual void Leave();

	//************************************
	// Method:    Get total time
	//************************************
	int GetTotalTime() const;

	//************************************
	// Method:    Is auto enter
	//************************************
	bool IsAutoEnter() const;

	//************************************
	// Method:    Set ready state
	//************************************
	void SetReadyState();

	//************************************
	// Method:    Exit
	//************************************
	virtual void Exit();

	//************************************
	// Method:    Is countdown done
	//************************************
	bool IsCountdownDone() const;

	//************************************
	// Method:    Reg countdown complete evt
	// Parameter: CountDownCplCallback callback
	//************************************
	void RegCountdownCpl(CountDownCplCallback callback);
};