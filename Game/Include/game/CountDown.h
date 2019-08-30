#pragma once

#include <functional>
using namespace std;
using namespace std::placeholders;

#include "tc/Timer.h"
using namespace tc;


namespace game
{
	class CountDown;

	// void*:	CountDown *
	// void*:	void *
	using CountdownCallback = std::function < void(CountDown*, void*) >;


	// Countdown
	class CountDown
	{
	public:
		//************************************
		// Method:    Constructor
		// Parameter: int nTime
		// Parameter: int nStepSize
		//************************************
		CountDown(int nTime, int nStepSize);

		virtual ~CountDown();

	private:
		int nTime;			// time
		int nStepSize;		// step size
		int nRemainTime;	// remain time
		int nRunnedTime;	// runned time
		bool bIsDone;		// whether countdown done

	private:
		Timer* pTimer;			// timer
		void* pObj;				// obj
		CountdownCallback fn;	// callback

	private:
		//************************************
		// Method:    OnTimer
		// Parameter: Timer * pObj
		// Parameter: int count
		// Parameter: void * pParam1
		// Parameter: void * pParam1
		//************************************
		void OnTimer(Timer* pObj, int count, void* pParam1, void* pParam2);

		//************************************
		// Method:    Countdown done evt handle
		//************************************
		void OnCountdownDone();

	public:
		//************************************
		// Method:    Get time
		//************************************
		int GetTotalTime() const;

		//************************************
		// Method:    Get remain time
		//************************************
		int GetRemainTime() const;

		//************************************
		// Method:    Get runned time
		//************************************
		int GetRunnedTime() const;

		//************************************
		// Method:    Is done
		//************************************
		bool IsDone();

		//************************************
		// Method:    Start
		//************************************
		void Start();

		//************************************
		// Method:    Stop
		//************************************
		void Stop();

		//************************************
		// Method:    Reset
		//************************************
		void Reset();

		//************************************
		// Method:    Init
		//************************************
		void Init();

		//************************************
		// Method:    Exit
		//************************************
		void Exit();

		//************************************
		// Method:    Attach obj
		// Parameter: void* pObj
		//************************************
		void AttachObj(void* pObj);

		//************************************
		// Method:    Reg countdown done evt
		// Parameter: CountdownCallback fn
		//************************************
		void RegDoneEvt(CountdownCallback fn);
	};
}