#pragma once
#include <queue>
#include "SocketEvt.h"

using namespace std;

namespace tc
{
	// socket���ݴ�����
	class SocketDataHandler
	{
	public:
		SocketDataHandler();
		virtual ~SocketDataHandler();

	protected:
		queue<SocketEvt*> quSocketEvts;	// socket�¼�����

	protected:
		//************************************
		// Method:    socket�¼�����
		//************************************
		virtual void OnSocketEvtProcess(SocketEvt* pEvt);

	public:
		//************************************
		// Method:    ���һ��socket�¼�
		//************************************
		virtual void PushSocketEvt(SocketEvt* pEvt);

		//************************************
		// Method:    socket�¼������Ƿ�Ϊ��
		//************************************
		virtual bool IsEmpty();

		//************************************
		// Method:    ���socket�¼�����
		//************************************
		virtual void Clear();

		//************************************
		// Method:    ����socket�¼�����
		//************************************
		virtual void ProcessSocketEvt();
	};
}