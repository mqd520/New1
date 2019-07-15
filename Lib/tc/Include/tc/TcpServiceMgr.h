#pragma once
#include "TcpService.h"
#include <queue>
using namespace std;

namespace tc
{
	// tcp������������
	class TcpServiceMgr
	{
	public:
		TcpServiceMgr();
		~TcpServiceMgr();

	private:
		vector<TcpService*> vecTcpSrv;	// tcp������󼯺�

	public:
		//************************************
		// Method:    ����һ��tcp�������
		// Parameter: tcp�������
		//************************************
		void Remove(TcpService* pTcpSrv);

		//************************************
		// Method:    �������tcp�������
		//************************************
		void Clear();

		//************************************
		// Method:    ����һ��tcp�������
		// Parameter: tcp�������
		//************************************
		void PushTcpService(TcpService* pTcpSrv);

		//************************************
		// Method:    ��ȡָ��socket������tcp�������
		// Return:	  tcp�������
		// Parameter: socket
		//************************************
		TcpService* GetTcpSrvBySocket(SOCKET socket);
	};
}