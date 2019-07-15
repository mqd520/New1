#pragma once
#include "Def.h"
#include "Timer.h"

namespace tc
{
	// ����������
	class KeepAliveSrv
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: int clientId
		// Parameter: nTimeout:		��������ʱʱ��
		// Parameter: nMaxCount:	����ʧ������������
		// Parameter: pObj1:	TcpService����
		// Parameter: pObj2:	PacketSrv����
		//************************************
		KeepAliveSrv(int clientId = 0, int nTimeout = TC_KeepAlive_Timeout, int nMaxCount = TC_KeepAlive_MaxMissCount, void* pObj1 = NULL, void* pObj2 = NULL);
		virtual ~KeepAliveSrv();

	protected:
		const int nTimeout;		// Ĭ����������ʱʱ��
		const int nMaxCount;	// Ĭ������ʧ������������
		void* pObj1;			// TcpService����
		void* pObj2;			// PacketSrv����
		int nMissCount;			// ��ʧ����
		Timer tTimeout;			// ��ʧ��������ʱ��
		int nClientId;			// clientId
		string strPeerIp;		// ip
		int nPort;				// port

	protected:
		//************************************
		// Method:    ����PacketSrv����
		// Parameter: void pObj1:	TcpService����
		// Parameter: void pObj2:	PacketSrv����
		//************************************
		virtual void AttachObj(void* pObj1, void* pObj2);

		//************************************
		// Method:    ��ȡ�Զ�ip
		//************************************
		string GetPeerIp();

		//************************************
		// Method:    ��ȡ�Զ�port
		//************************************
		int GetPeerPort();

		//************************************
		// Method:    ����������
		//************************************
		virtual void SendKeepAlive(int clientId = 0);

		//************************************
		// Method:    �������¼�����
		//************************************
		virtual void OnKeepAlive();

		//************************************
		// Method:    ��ʱ���¼�����
		// Parameter: ��ʱ������
		// Parameter: ����
		// Parameter: void * pParam1
		// Parameter: void * pParam2
		//************************************
		void OnTimerTimeout(Timer* pTimer, int count, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ��ʧ�������¼�����
		// Parameter: count:	������ʧ����
		// Parameter: b:	�Ƿ��ѳ�������������
		//************************************
		virtual void OnMissKeepAlive(int count, bool b = true);

		//************************************
		// Method:    ��ʼ������
		//************************************
		virtual void StartKeepAlive();

		//************************************
		// Method:    �ر�������
		//************************************
		virtual void CloseKeepAlive();

		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit();
	};
}