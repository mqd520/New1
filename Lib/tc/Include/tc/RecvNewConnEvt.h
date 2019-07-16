#pragma once
#include <string>
#include "TcpEvt.h"

using namespace std;

namespace tc
{
	// �յ��������¼�
	class RecvNewConnEvt : public TcpEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: tcp����
		// Parameter: �ͻ���socket
		//************************************
		RecvNewConnEvt(TcpService* pSrv, SOCKET client);

	private:
		bool bIsAllow;		// whether allow by the server

	public:
		//************************************
		// Method:    Is Allow
		//************************************
		bool IsAllow();

		//************************************
		// Method:    Allow the new connection
		//************************************
		void Allow();
	};
}