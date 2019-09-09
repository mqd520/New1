#include "stdafx.h"
#include "Include/com/Lock.h"

namespace com
{
	Lock::Lock() :
		bLeaved(true)
	{
		InitializeCriticalSection(&crSection);
	}

	Lock::~Lock()
	{
		Leave();

		DeleteCriticalSection(&crSection);
	}

	void Lock::Enter()
	{
		bLeaved = false;
		EnterCriticalSection(&crSection);
	}

	void Lock::Leave()
	{
		if (!bLeaved)
		{
			bLeaved = true;
			LeaveCriticalSection(&crSection);
		}
	}
}