#pragma once

#include <vector>
#include <queue>
using namespace std;

#include "Include/com/Timer.h"
#include "TimerThread1.h"
#include "TimerThread2.h"
#include "Include/com/Lock.h"


namespace com
{
	// Timer Mgr
	class TimerMgr final
	{
	private:
		TimerMgr();

	private:
		static vector<Timer*> vecTimers;	// timer list
		static queue<int> quUnitTimes;		// unit time queue
		static TimerThread1 thd1;
		static TimerThread2 thd2;
		static Lock lock1;
		static Lock lock2;

	public:
		static void AddTimer(Timer* pTimer);

		static void RemoveTimer(Timer* pTimer);

		static void PushUnitTime(int time);

		static void ProcessUnitTime();
	};
}