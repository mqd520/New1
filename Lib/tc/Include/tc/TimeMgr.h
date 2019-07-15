#pragma once
#include <queue>
#include "ThreadLock.h"

using namespace std;

namespace tc
{
	// ʱ�����
	class TimeMgr
	{
	public:
		TimeMgr();
		~TimeMgr();

	private:
		queue<int> queueTime;	// ʱ�����
		CThreadLock lock1;		// �߳���, ���queueTime����

	public:
		//************************************
		// Method:    ���һ��ʱ������
		//************************************
		void Add(int millsecond);

		//************************************
		// Method:    ���ʱ������
		//************************************
		void Clear();

		//************************************
		// Method:    ����ʱ������
		//************************************
		void ProcessTime();
	};
}