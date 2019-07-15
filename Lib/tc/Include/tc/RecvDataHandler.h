#pragma once
#include "SocketDataHandler.h"

namespace tc
{
	// �����ݴ�������
	class RecvDataHandler : public SocketDataHandler
	{
	public:
		RecvDataHandler();
		~RecvDataHandler();

	private:
		//************************************
		// Method:    �յ��������¼�����
		//************************************
		void OnRecvNewConn(SocketEvt* pEvt);

		//************************************
		// Method:    �յ��Զ������¼�����
		//************************************
		void OnRecvPeerData(SocketEvt* pEvt);

		//************************************
		// Method:    ���ӶϿ��¼�����
		//************************************
		void OnConnDisconnect(SocketEvt* pEvt);

		//************************************
		// Method:    ���ӷ��������¼�����
		//************************************
		void OnConnectCpl(SocketEvt* pEvt);

	protected:
		//************************************
		// Method:    socket�¼�����
		//************************************
		virtual void OnSocketEvtProcess(SocketEvt* pEvt) override;
	};
}