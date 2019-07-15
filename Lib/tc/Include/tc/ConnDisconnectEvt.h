#pragma once
#include "TcpEvt.h"

namespace tc
{
	// ���ӶϿ��¼�
	class ConnDisconnectEvt : public TcpEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: tcp service
		// Parameter: SOCKET sendrecv
		// Parameter: ���ӶϿ�ԭ��
		//************************************
		ConnDisconnectEvt(TcpService* pSrv, SOCKET sendrecv, EDisconnReason reason);

	private:
		EDisconnReason reason;	// ���ӶϿ�ԭ��

	public:
		//************************************
		// Method:    ��ȡ�Ͽ�ԭ��
		//************************************
		EDisconnReason GetReason();
	};
}