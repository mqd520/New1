#pragma once
#include <queue>
#include "TcpEvt.h"

using namespace std;

namespace tc
{
	// tcp�¼�������
	class TcpEvtMgr
	{
	public:
		TcpEvtMgr();
		~TcpEvtMgr();

	private:
		queue<TcpEvt*> queueEvent;	// tcp�¼�����

	public:
		//************************************
		// Method:    tcp�¼������Ƿ�Ϊ��
		//************************************
		bool IsEmpty();

		//************************************
		// Method:    ׷��һ��tcp�����¼�
		// Parameter: tcp�����¼�
		//************************************
		void PushTcpEvent(TcpEvt* pEvent);

		//************************************
		// Method:    ���tcp�¼�����
		//************************************
		void Clear();

		//************************************
		// Method:    ����tcp�¼�
		//************************************
		void ProcessTcpEvt();
	};
}