#pragma once
#include "ThreadEntry.h"

namespace tc
{
	// ����ʱ�������߳�
	class TimeThread1 : public CThreadEntry
	{
	public:
		TimeThread1();
		~TimeThread1();

	private:
		int nTime;	//���ʱ��

	protected:
		//************************************
		// Method:    �߳������¼�����
		//************************************
		virtual void OnThreadExecute() override;
	};
}