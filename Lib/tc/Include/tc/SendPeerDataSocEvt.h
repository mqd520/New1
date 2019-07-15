#pragma once
#include "SocketEvt.h"

namespace tc
{
	// ���ͶԶ�����socket�¼�
	class SendPeerDataSocEvt : public SocketEvt
	{
	public:
		SendPeerDataSocEvt(SOCKET send, BYTE* buf, int len);
		~SendPeerDataSocEvt();

	private:
		SOCKET	send;	// �������ݵ�socket
		BYTE*	pBuf;	// �������ݻ�����
		int		nLen;	// �������ݻ���������

	public:
		//************************************
		// Method:    ��ȡ�������ݵ�socket
		//************************************
		SOCKET	GetSocket();

		//************************************
		// Method:    ��ȡ�������ݵĻ�����
		//************************************
		BYTE*	GetBuf();

		//************************************
		// Method:    ��ȡ�������ݵĻ���������
		//************************************
		int		GetLen();
	};
}