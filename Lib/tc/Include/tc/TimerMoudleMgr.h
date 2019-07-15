#pragma once
#include "TimeThread1.h"
#include "TimeThread2.h"
#include "TimeMgr.h"
#include "TimerMgr.h"

namespace tc
{
	// ��ʱ��ģ�����
	class TimerMoudleMgr
	{
	public:
		TimerMoudleMgr();
		~TimerMoudleMgr();

	private:
		static bool bInited;			// �Ƿ��ѳ�ʼ��
		static int nTimeUnit;			// ʱ����С��λ
		static TimeThread2 timeThread1;	// ����ʱ�߳�
		static TimeThread1 timeThread2;	// ���ɳ�ʱ�߳�
		static TimeMgr timeMgr;			// ��ʱ������
		static TimerMgr timerMgr;		// ��ʱ����

	public:
		//************************************
		// Method:    ��ʼ��
		//************************************
		static void Init();

		//************************************
		// Method:    �˳�
		//************************************
		static void Exit();

		//************************************
		// Method:    ��ȡ��ʱ��λʱ��
		//************************************
		static int GetTimeUnit();

		//************************************
		// Method:    ���ó�ʱ��λʱ��
		// Parameter: ��ʱʱ��
		//************************************
		static void SetTimeUnit(int millsecond);

		//************************************
		// Method:    ��ȡ��ʱ���������
		//************************************
		static TimerMgr* GetTimerMgr();

		//************************************
		// Method:    ��ȡʱ��������
		//************************************
		static TimeMgr* GetTimeMgr();
	};
}