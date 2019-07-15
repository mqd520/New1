#pragma once
#include "ThreadEvent.h"
#include <process.h>
#include "ThreadEntry.h"

namespace tc
{
	//�߳���
	class CThread
	{
	private:
		HANDLE m_hThread;//�߳̾��

		CThreadEvent m_evtReady;
		CThreadEvent m_evtGiven;
		CThreadEntry* m_pEntry;

	private:
		//************************************
		// Method:    �߳����
		//************************************
		static unsigned WINAPI  Run(LPVOID lParam);

	public:
		CThread(CThreadEntry* pEntry);
		~CThread();

		//************************************
		// Method:    �����߳�
		//************************************
		void Run();

		void Wait(int millsecond = 0);

		//************************************
		// Method:    �߳�ִ��
		//************************************
		void Execute();

		//************************************
		// Method:    �߳�ִ�����
		//************************************
		void ExecuteCmp();
	};
}