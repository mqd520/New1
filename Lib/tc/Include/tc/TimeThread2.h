#pragma once
#include "ThreadEntry.h"

namespace tc
{
	// ����ʱ�����߳�
	class TimeThread2 : public CThreadEntry
	{
	public:
		TimeThread2();
		~TimeThread2();

	protected:
		//************************************
		// Method:    �߳������¼�����
		//************************************
		virtual void OnThreadExecute() override;
	};
}