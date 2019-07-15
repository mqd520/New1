#pragma once
#include "TcpEvt.h"

namespace tc
{
	// ���ӷ��������¼�
	class ConnectSrvCplEvt : public TcpEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: tcp ������
		// Parameter: socket
		// Parameter: �����Ƿ�ɹ�
		//************************************
		ConnectSrvCplEvt(TcpService* pSrv, SOCKET socket, bool success);
		~ConnectSrvCplEvt();

	private:
		bool	bSuccess;		// �����Ƿ�ɹ�

	public:
		//************************************
		// Method:    ��ȡ���ӽ��
		//************************************
		bool	GetConnectResult();
	};
}