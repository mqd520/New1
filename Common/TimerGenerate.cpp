#include "stdafx.h"
#include "TimerGenerate.h"
#include "TimerMgr.h"
#include <WinSock2.h>


#define UnitTime		(100)		// unit time


namespace com
{
	TimerGenerate::TimerGenerate()
	{

	}

	void TimerGenerate::GenerateTime()
	{
		TimerMgr::PushUnitTime(UnitTime);
	}
}