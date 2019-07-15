#pragma once
#include <vector>
#include "ThreadLock.h"
#include "Timer.h"

using namespace std;

namespace tc
{
	//��ʱ������
	class TimerMgr
	{
	public:
		TimerMgr();
		~TimerMgr();

	private:
		vector<Timer*> vecTimer;	// ��ʱ������
		CThreadLock lock1;			// �߳���, ��� vecTimer

	public:
		//************************************
		// Method:    ���һ����ʱ��
		// Parameter: ��ʱ��
		//************************************
		void Add(Timer* pTimer);

		//************************************
		// Method:    �Ƴ�һ����ʱ��
		// Parameter: ��ʱ��
		//************************************
		void Remove(Timer* pTimer);

		//************************************
		// Method:    ������ж�ʱ��
		//************************************
		void Clear();

		//************************************
		// Method:    ��ȡ��ʱ����Ŀ
		//************************************
		int Count();

		//************************************
		// Method:    ʱ���¼�����
		// Parameter: ��ʱʱ��
		//************************************
		void OnTimer(int millsecond);
	};
}