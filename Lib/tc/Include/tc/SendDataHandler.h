#pragma once
#include "SocketDataHandler.h"

namespace tc
{
	// �����ݴ�����
	class SendDataHandler : public SocketDataHandler
	{
	public:
		SendDataHandler();
		~SendDataHandler();

	private:
		//************************************
		// Method:    ���ͶԶ������¼�����
		//************************************
		void OnSendPeerData(SocketEvt* pEvt);

	protected:
		//************************************
		// Method:    socket�¼�����
		//************************************
		virtual void OnSocketEvtProcess(SocketEvt* pEvt) override;
	};
}