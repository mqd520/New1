#include "stdafx.h"
#include "GameStatus.h"

#include "tc/TimerMoudleMgr.h"


#define StepSize		(1000)			// countdown step size time


GameStatus::GameStatus(EGameStatus status, bool isAutoEnterNext /*= false*/, int nTime /*= 0*/) :
status(status),
nTime(nTime),
bIsAutoEnterNext(isAutoEnterNext),
bIsReady(false),

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

void GameStatus::OnCountdownDone(CountDown* pCountDown, void* pObj)
{
	for (vector<CountDownCplCallback>::iterator it = vecFns.begin(); it != vecFns.end(); it++)
	{
		if (!(*it)._Empty())
		{
			(*it)(this, pCountDown->GetTotalTime());
		}
	}
}

EGameMainStatus GameStatus::GetCurGameMainStatus() const
{
	return EGameMainStatus::None;
}

EGameStatus GameStatus::GetCurGameStatus() const
{
	return status;
}

EGameStatus GameStatus::GetNextStatus() const
{
	return EGameStatus::None;
}

EGameStatus GameStatus::GetLastStatus() const
{
	return EGameStatus::None;
}

void GameStatus::Enter()
{
	bIsReady = false;
	
	StartCountdown();
}

void GameStatus::Leave()
{
	bIsReady = false;
	StopCountdown();
}

bool GameStatus::IsReady() const
{
	return bIsReady;
}

int GameStatus::GetTotalTime() const
{
	return nTime;
}

bool GameStatus::IsAutoEnter() const
{
	return bIsAutoEnterNext;
}

void GameStatus::SetReadyState()
{
	bIsReady = true;
}

void GameStatus::Exit()
{
	if (pCountdown)
	{
		delete pCountdown;
		pCountdown = nullptr;
	}
}

bool GameStatus::IsCountdownDone() const
{
	if (pCountdown)
	{
		return pCountdown->IsDone();
	}

	return true;
}

void GameStatus::RegCountdownCpl(CountDownCplCallback callback)
{
	vecFns.push_back(callback);
}