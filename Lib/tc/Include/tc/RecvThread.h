#pragma once
#include "ThreadEntry.h"

namespace tc
{
	//���������߳�
	class RecvThread : public CThreadEntry
	{
	protected:
		//************************************
		// Method:    �߳������¼�����
		//************************************
		void OnThreadExecute();

	public:
		RecvThread();
		~RecvThread();

		//************************************
		// Method:    ��ʼ�����߳�
		//************************************
		void Run();
	};
}