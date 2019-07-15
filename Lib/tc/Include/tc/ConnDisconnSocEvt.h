#pragma once
#include "SocketEvt.h"

namespace tc
{
	// ���ӶϿ�socket�¼�
	class ConnDisconnSocEvt : public SocketEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: sendrecv:	�շ����ݵ�socket
		//************************************
		ConnDisconnSocEvt(SOCKET sendrecv);
		~ConnDisconnSocEvt();

	private:
		SOCKET sendrecv;	// ������socket

	public:
		SOCKET GetSocket() const;
	};
}