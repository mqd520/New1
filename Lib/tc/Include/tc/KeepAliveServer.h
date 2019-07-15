#pragma once
#include "KeepAliveSrv.h"

namespace tc
{
	// keepAliveServer
	class KeepAliveServer : public KeepAliveSrv
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: int clientId
		// Parameter: int nRecvTimespan	����˽��տͻ����������ļ��ʱ��
		// Parameter: int nTimeout:		��ʧ��������ʱʱ��
		// Parameter: int nMaxCount:	����ʧ������
		// Parameter: void * pObj1
		// Parameter: void * pObj2
		//************************************
		KeepAliveServer(
			int clientId = 0, int nRecvTimespan = TC_KeepAlive_RecvTimespan, 
			int nTimeout = TC_KeepAlive_Timeout, int nMaxCount = TC_KeepAlive_MaxMissCount,
			void* pObj1 = NULL, void* pObj2 = NULL);
		virtual ~KeepAliveServer();

	protected:
		const int nRecvTimespan;	// ����˽��տͻ����������ļ��ʱ��
		DWORD dwLastRecv;			// �ϴν���ʱ��(��ȷ������)

	protected:
		//************************************
		// Method:    �������¼�����
		//************************************
		virtual void OnKeepAlive() override;
	};
}