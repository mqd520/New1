#pragma once
#include "SocketEvt.h"

namespace tc
{
	// �յ��Զ�����socket�¼�
	class RecvPeerDataSocEvt : public SocketEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: recv:		�������ݵ�socket
		// Parameter: pBuf:		�������ݵĻ�����ָ��
		// Parameter: len:		�������ݵĻ�����ָ�볤��
		//************************************
		RecvPeerDataSocEvt(SOCKET recv, BYTE* pBuf, int len);
		~RecvPeerDataSocEvt();

	private:
		SOCKET	recv;		// �������ݵ�socket
		BYTE*	pBuf;		// �������ݵĻ�����ָ��
		int		len;		// �������ݵĻ�����ָ�볤��

	public:
		//************************************
		// Method:    ��ȡsocket
		//************************************
		SOCKET GetSocket() const;

		//************************************
		// Method:    ��ȡ���ݻ�����ָ��
		//************************************
		BYTE* GetBuf() const;

		//************************************
		// Method:    ��ȡ���ݻ�����ָ�볤��
		//************************************
		int GetLen() const;
	};
}