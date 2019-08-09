#include "stdafx.h"
#include "Include/game/CountDown.h"

#include "tc/TimerMoudleMgr.h"
using namespace tc;


namespace game
{
	CountDown::CountDown(int nTime, int nStepSize) :
		nTime(nTime),
		nStepSize(nStepSize),
		nRemainTime(nTime),
		nRunnedTime(0),
		bIsDone(false),
		pTimer(nullptr),
		pObj(nullptr)
	{
		if (nTime > 0 && nStepSize > 0)
		{
			pTimer = new Timer(nStepSize);
			pTimer->SetCallback(std::bind(&CountDown::OnTimer, this, _1, _2, _3, _4));
		}
	}

	CountDown::~CountDown()
	{
		Exit();
	}

	void CountDown::OnTimer(Timer* pObj, int count, void* pParam1, void* pParam2)
	{
		nRunnedTime += nStepSize;
		if (nRunnedTime > nTime)
		{
			nRunnedTime = nTime;
		}

		nRemainTime -= nStepSize;
		if (nRemainTime < 0)
		{
			nRemainTime = 0;
		}

		if (nRemainTime == 0)
		{
			OnCountdownDone();
		}
	}

	void CountDown::OnCountdownDone()
	{
		if (pTimer)
		{
			pTimer->Stop();
		}

		bIsDone = true;

		if (!fn._Empty())
		{
			fn(this, pObj);
		}
	}

	int CountDown::GetTotalTime() const
	{
		return nTime;
	}

	int CountDown::GetRemainTime() const
	{
		return nRemainTime;
	}

	int CountDown::GetRunnedTime() const
	{
		return nRunnedTime;
	}

	bool CountDown::IsDone()
	{
		return bIsDone;
	}

	void CountDown::Start()
	{
		nRunnedTime = 0;
		nRemainTime = nTime;
		bIsDone = false;

		if (pTimer && !pTimer->IsRun())
		{
			pTimer->Run();
		}
	}

	void CountDown::Stop()
	{
		nRunnedTime = 0;
		nRemainTime = nTime;
		bIsDone = false;

		if (pTimer)
		{
			pTimer->Stop();
		}
	}

	void CountDown::Reset()
	{
		nRunnedTime = 0;
		nRemainTime = nTime;
		bIsDone = false;

		if (pTimer)
		{
			pTimer->Reset();
		}
	}

	void CountDown::Init()
	{

	}

	void CountDown::Exit()
	{
		if (pTimer)
		{
			TimerMoudleMgr::GetTimerMgr()->Remove(pTimer);
			delete pTimer;
			pTimer = nullptr;

			nRunnedTime = 0;
			nRemainTime = nTime;
			bIsDone = false;
		}
	}

	void CountDown::AttachObj(void* pObj)
	{
		this->pObj = pObj;
	}

	void CountDown::RegDoneEvt(CountdownCallback fn)
	{
		this->fn = fn;
	}
}