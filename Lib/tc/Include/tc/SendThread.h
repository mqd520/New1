#pragma once
#include "ThreadEntry.h"

namespace tc
{
	//���������߳�
	class SendThread : public CThreadEntry
	{
	protected:
		//************************************
		// Method:    �߳������¼�����
		//************************************
		void OnThreadExecute();

	public:
		SendThread();
		~SendThread();

		//************************************
		// Method:    ��ʼ�����߳�
		//************************************
		void Run();
	};
}