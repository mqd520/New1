#include "stdafx.h"
#include "TimerThread2.h"
#include "TimerGenerate.h"

namespace com
{
	TimerThread2::TimerThread2() :
		Thread(100, "TimerGenerateThread")
	{

	}

	void TimerThread2::OnWhile()
	{
		TimerGenerate::GenerateTime();
	}
}