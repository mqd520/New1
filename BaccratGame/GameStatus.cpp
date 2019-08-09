#include "stdafx.h"
#include "GameStatus.h"

#include "tc/TimerMoudleMgr.h"

#define StepSize		(1000)			// countdown step size time


GameStatus::GameStatus(EGameStatus status, int nTime /*= 0*/) :
status(status),
pCountdown(nullptr)
{
	if (nTime > 0)
	{
		pCountdown = new CountDown(nTime, StepSize);
		pCountdown->AttachObj(this);
		pCountdown->RegDoneEvt(std::bind(&GameStatus::OnCountdownDone, this, _1, _2));
	}
}

GameStatus::~GameStatus()
{
	Exit();
}

void GameStatus::StartCountdown()
{
	if (pCountdown)
	{
		pCountdown->Start();
	}
}

void GameStatus::StopCountdown()
{
	if (pCountdown)
	{
		pCountdown->Stop();
	}
}

void GameStatus::ResetCountdown()
{
	if (pCountdown)
	{
		pCountdown->Reset();
	}
}

bool GameStatus::IsCountdownDone()
{
	if (pCountdown)
	{
		return pCountdown->IsDone();
	}
	
	return false;
}

void GameStatus::OnCountdownDone(CountDown* p1, void* pObj)
{
	
}

EGameMainStatus GameStatus::GetCurGameMainStatus()
{
	return EGameMainStatus::None;
}

EGameStatus GameStatus::GetCurGameStatus()
{
	return status;
}

EGameStatus GameStatus::GetNextStatus()
{
	return EGameStatus::None;
}

EGameStatus GameStatus::GetLastStatus()
{
	return EGameStatus::None;
}

void GameStatus::Enter()
{

}

void GameStatus::Leave()
{
	StopCountdown();
}

bool GameStatus::IsCompleted()
{
	return true;
}

void GameStatus::Exit()
{
	if (pCountdown)
	{
		delete pCountdown;
		pCountdown = nullptr;
	}
}