#include "stdafx.h"
#include "Include/com/Thread.h"

namespace com
{
	typedef vector<ThreadStartCallback>::iterator	IT1;
	typedef vector<ThreadWhileCallback>::iterator	IT2;
	typedef vector<ThreadExitCallback>::iterator	IT3;


	Thread::Thread(int nMillSecond /*= ThreadSleepMillTime*/, string name /*= "Thread"*/) :
		strThreadName(name),
		bRunning(false),
		bExited(false),
		nMillSecond(nMillSecond),
		hThd(NULL),
		lpParam(nullptr)
	{

	}

	Thread::~Thread()
	{

	}

	int Thread::ThreadMain()
	{
		bRunning = true;

		OnStart();

		OnExecute();

		OnExit();

		return 0;
	}

	void Thread::OnStart()
	{
		printf("Thread start: %s \n", strThreadName.c_str());

		for (IT1 it = vecStartCallbacks.begin(); it != vecStartCallbacks.end(); it++)
		{
			if (!it->_Empty())
			{
				(*it)(this);
			}
		}
	}

	void Thread::OnExecute()
	{
		while (!bExited)
		{
			OnWhile();

			::Sleep(nMillSecond);
		}
	}

	void Thread::OnWhile()
	{
		for (IT2 it = vecWhileCallbacks.begin(); it != vecWhileCallbacks.end(); it++)
		{
			if (!it->_Empty())
			{
				(*it)(this);
			}
		}
	}

	void Thread::OnExit()
	{
		printf("Thread exit: %s \n", strThreadName.c_str());

		for (IT3 it = vecWhileCallbacks.begin(); it != vecWhileCallbacks.end(); it++)
		{
			if (!it->_Empty())
			{
				(*it)(this);
			}
		}
	}

	HANDLE Thread::GetThreadHandle() const
	{
		return 0;
	}

	int Thread::GetThreadId() const
	{
		return 0;
	}

	bool Thread::IsRun() const
	{
		return bRunning;
	}

	string Thread::GetThreadName() const
	{
		return strThreadName;
	}

	void Thread::SetThreadName(string name)
	{
		strThreadName = name;
	}

	int Thread::GetSleepTime() const
	{
		return nMillSecond;
	}

	void Thread::SetSleepTime(int time)
	{
		nMillSecond = time;
	}

	void Thread::Run(LPVOID lpParam /*= nullptr*/)
	{
		if (!bRunning && hThd == NULL)
		{
			bExited = false;
			this->lpParam = lpParam;
			hThd = (HANDLE)_beginthreadex(0, 0, ThreadRun::Run, this, 0, NULL);
		}
	}

	void Thread::Exit(int timeout /*= 1 * 1000*/)
	{
		if (bRunning)
		{
			bExited = true;

			DWORD dwResult = ::WaitForSingleObject(hThd, timeout);
			if (dwResult == WAIT_TIMEOUT)
			{
				::TerminateThread(hThd, 0);
			}
			::CloseHandle(hThd);
			hThd = NULL;
			bRunning = false;
		}
	}

	void Thread::RegStartEvt(ThreadStartCallback fn)
	{
		vecStartCallbacks.push_back(fn);
	}

	void Thread::RegWhileEvt(ThreadWhileCallback fn)
	{
		vecWhileCallbacks.push_back(fn);
	}

	void Thread::RegExitEvt(ThreadExitCallback fn)
	{
		vecExitCallbacks.push_back(fn);
	}


	unsigned int WINAPI ThreadRun::Run(LPVOID lParam)
	{
		int quitCode = 0;

		Thread* pThd = (Thread*)lParam;
		if (pThd)
		{
			quitCode = pThd->ThreadMain();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			printf("Thread start error, name: %s, handle: %d, Id: %d \n",
				pThd->GetThreadName().c_str(), pThd->GetThreadHandle(), pThd->GetThreadId());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			quitCode = -1;
		}

		return quitCode;
	}
}