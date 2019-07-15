#pragma once

#define SLEEPTIME	5	// �߳�Ĭ������ʱ��

namespace tc
{


	class CThread;

	//�߳������
	class CThreadEntry
	{
	protected:
		CThread* m_pThread;//�̶߳���
		volatile bool m_bExist;//�߳��Ƿ�Ӧ���˳�
		bool m_bRun;//�߳��Ƿ��ѿ���
		int m_nSleepMillSecond;//����ʱ��

	protected:
		//************************************
		// Method:    ��������ʱ��
		//************************************
		void SetSleepTime(int millsecond = SLEEPTIME);

	protected:
		friend class CThread;
		//************************************
		// Method:    �߳�ִ���¼�����
		// Returns:   �Ƿ�Ӧ���˳�
		// Qualifier:
		//************************************
		virtual void OnThreadExecute();

		//************************************
		// Method:    �߳�ִ������¼�����
		//************************************
		virtual void OnThreadCmp();

		//************************************
		// Method:    �߳��Ƿ�����˳�
		//************************************
		bool IsCanExit();

		//************************************
		// Method:    ִ��һ��ҵ����������
		//************************************
		virtual void Sleep();

	public:
		CThreadEntry();
		~CThreadEntry();

		//************************************
		// Method:    ��ʼ�����߳�
		//************************************
		virtual void Run();

		//************************************
		// Method:    �˳��߳�
		//************************************
		virtual void Exit();
	};
}