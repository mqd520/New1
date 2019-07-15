#pragma once
#include "SocketEvt.h"

namespace tc
{
	// �������socket�¼�
	class ConnectCplSocEvt : public SocketEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: �������ӵ�socket
		// Parameter: �����Ƿ�ɹ�
		//************************************
		ConnectCplSocEvt(SOCKET socket, bool success);
		~ConnectCplSocEvt();

	private:
		SOCKET	socket;		// �������ӵ�socket
		bool	success;	// �����Ƿ�ɹ�

	public:
		//************************************
		// Method:    �������ӵ�socket
		//************************************
		SOCKET	GetSocket() const;

		//************************************
		// Method:    ��ȡ�����Ƿ�ɹ�
		//************************************
		bool	GetResult() const;
	};
}