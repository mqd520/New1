#pragma once
#include <functional>
using namespace std;
using namespace std::placeholders;

namespace tc
{
	class Timer;
	class TimerMgr;

	// ��ʱ���ص�����ָ��
	typedef std::function<void(Timer*, int, void*, void*)> Fun3;

	// ��ʱ��
	class Timer
	{
	public:
		Timer(int timeout = 1000, int count = 0);
		~Timer();

	private:
		int nTimeout;			// ���ʱ��(����)
		int nCount;				// ���д���,0:��������
		Fun3 fun;				// ��ʱ���ص�����ָ��
		void* pParam1;			// �ص��������Ӳ���1
		void* pParam2;			// �ص��������Ӳ���2
		bool bRunning;			// �Ƿ���������
		int nTimeouted;			// �Ѿ������ʱ��
		int nCounted;			// �Ѿ����еĴ���
		bool bInited;			// �Ƿ��ѳ�ʼ��

	private:
		friend class TimerMgr;
		void OnTimer(int millsecond);

		void Init();

	public:
		//************************************
		// Method:    ���ü��ʱ��(ms)
		//************************************
		void SetTimeout(int millsecond);

		//************************************
		// Method:    ���ûص�����
		//************************************
		void SetCallback(Fun3 fun, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ��ʼ���ж�ʱ��
		//************************************
		void Run();

		//************************************
		// Method:    ֹͣ��ʱ(�����������)
		//************************************
		void Stop();

		//************************************
		// Method:    ��ͣ��ʱ
		//************************************
		void Pause();

		//************************************
		// Method:    �ָ���ʱ
		//************************************
		void Resume();

		//************************************
		// Method:    ����ʱ��
		//************************************
		void Reset();

		//************************************
		// Method:    �Ƿ�������
		//************************************
		bool IsRun();

		//************************************
		// Method:    ��ȡ���д���
		//************************************
		int Count();
	};
}