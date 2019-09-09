#pragma once

#include "Include/com/Thread.h"


namespace com
{
	// Timer trigger thread
	class TimerThread1 : public Thread
	{
	public:
		TimerThread1();

	protected:
		//************************************
		// Method:    Thread inner while evt handler
		//************************************
		void OnWhile() override;
	};
}