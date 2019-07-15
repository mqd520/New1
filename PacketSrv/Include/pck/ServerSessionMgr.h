#pragma once
#include "ServerSession.h"
#include <vector>

using namespace std;

namespace pck
{
	// session mgr
	class ServerSessionMgr
	{
	public:
		ServerSessionMgr();

	protected:
		vector<ServerSession*>	vecSessions;	// session����

	public:
		//************************************
		// Method:    ��ȡָ��client id session
		// Parameter: int clientId
		//************************************
		ServerSession* GetSession(int clientId);

		//************************************
		// Method:    ����session
		// Parameter: int clientId
		// Parameter: void* pObj:	IGPacketSrvServer����
		// Parameter: recvPwd:	�Ƿ���Ҫ��֤�ͻ�������
		//************************************
		ServerSession* CreateSession(int clientId, void* pObj, bool recvPwd = true);

		//************************************
		// Method:    �ر�session
		// Parameter: int clientId
		//************************************
		void CloseSession(int clientId);

		//************************************
		// Method:    �ر�session
		//************************************
		void CloseSession();
	};
}