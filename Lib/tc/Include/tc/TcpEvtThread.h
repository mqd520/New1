#pragma once
#include "ThreadEntry.h"

namespace tc
{
	//tcp�¼��߳�
	class TcpEvtThread : public CThreadEntry
	{
	protected:
		//************************************
		// Method:    �߳������¼�����
		//************************************
		void OnThreadExecute();

	public:
		TcpEvtThread();
		~TcpEvtThread();

		//************************************
		// Method:    ��ʼ�����߳�
		//************************************
		void Run();
	};
}