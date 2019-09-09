#include "stdafx.h"
#include "TimerThread1.h"
#include "TimerMgr.h"

namespace com
{
	TimerThread1::TimerThread1() :
		Thread(100, "TimerTriggerThread")
	{

	}

	void TimerThread1::OnWhile()
	{
		__super::OnWhile();

		TimerMgr::ProcessUnitTime();
	}
}