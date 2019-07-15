#pragma once
#include <vector>
#include <queue>
#include "Def.h"
#include "TcpConnection.h"
#include "ThreadLock.h"

using namespace std;

namespace tc
{
	// tcp���ӹ�����
	class TcpConnectionMgr
	{
	public:
		TcpConnectionMgr();
		~TcpConnectionMgr();

	private:
		vector<TcpConnection*> vecTcpConn;		// tcp���Ӽ���
		CThreadLock m_lock;

	public:
		//************************************
		// Method:    ����һ��tcp����
		//************************************
		void PushTcpConn(TcpConnection* conn);

		//************************************
		// Method:    �Ƴ�ָ���շ����ݵ�socket������tcp���Ӷ���
		// Parameter: �շ����ݵ�socket
		//************************************
		void RemoveBySendRecvSocket(SOCKET socket);

		//************************************
		// Method:    ��ȡָ����(��)���ݵ�socket������tcp���Ӷ���
		// Parameter: ��(��)���ݵ�socket
		// Return:	  tcp���Ӷ���
		//************************************
		TcpConnection* GetBySendRecvSocket(SOCKET sendrecv);

		vector<TcpConnection*> GetByTcpService(TcpService* pTcpService);

		//************************************
		// Method:    ����������Ӷ���
		//************************************
		void Clear();

		//************************************
		// Method:    ����һ��tcp���Ӷ���
		//************************************
		void CreateTcpConnection(SOCKET socket, SOCKET accept = NULL, bool bEnable = true);

		//************************************
		// Method:    ��ȡ��������
		//************************************
		int Count();
	};
}