#include "stdafx.h"
#include "TimerMgr.h"

namespace com
{
	vector<Timer*>	TimerMgr::vecTimers;
	queue<int>		TimerMgr::quUnitTimes;
	TimerThread1	TimerMgr::thd1;
	TimerThread2	TimerMgr::thd2;
	Lock			TimerMgr::lock1;
	Lock			TimerMgr::lock2;


	TimerMgr::TimerMgr()
	{

	}

	void TimerMgr::AddTimer(Timer* pTimer)
	{
		lock2.Enter();

		vecTimers.push_back(pTimer);

		lock2.Leave();

		thd1.Run();
		thd2.Run();
	}

	void TimerMgr::RemoveTimer(Timer* pTimer)
	{
		lock2.Enter();

		for (vector<Timer*>::iterator it = vecTimers.begin(); it != vecTimers.end(); it++)
		{
			if (*it == pTimer)
			{
				vecTimers.erase(it);
				break;
			}
		}

		lock2.Leave();
	}

	void TimerMgr::PushUnitTime(int time)
	{
		//lock1.Enter();

		quUnitTimes.push(time);

		//lock1.Leave();
	}

	void TimerMgr::ProcessUnitTime()
	{
		while (true)
		{
			int val = 0;

			lock1.Enter();

			if (!quUnitTimes.empty())
			{
				val = quUnitTimes.front();
				quUnitTimes.pop();
			}
			else
			{
				lock1.Leave();

				break;
			}

			lock1.Leave();

			if (val > 0)
			{
				lock2.Enter();

				for (vector<Timer*>::iterator it1 = vecTimers.begin(); it1 != vecTimers.end(); it1++)
				{
					(*it1)->OnElapse(val);
				}

				lock2.Leave();
			}
		}
	}
}