#pragma once
#include "SocketEvt.h"

namespace tc
{
	// �յ�������socket�¼�
	class RecvNewConnSocEvt : public SocketEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: server:	�����socket
		// Parameter: clients:	���յ����¿ͻ���socket����
		//************************************
		RecvNewConnSocEvt(SOCKET server, vector<SOCKET>& clients);
		~RecvNewConnSocEvt();

	private:
		SOCKET server;				// ����˵�socket
		vector<SOCKET> vecClients;	// ���յ����¿ͻ���socket����

	public:
		SOCKET GetServerSocket() const;

		vector<SOCKET> GetClients();
	};
}