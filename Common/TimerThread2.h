#pragma once

#include "Include/com/Thread.h"


namespace com
{
	// Timer generate thread
	class TimerThread2 : public Thread
	{
	public:
		TimerThread2();

	protected:
		//************************************
		// Method:    Thread while evt handler
		//************************************
		void OnWhile() override;
	};
}