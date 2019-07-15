#pragma once
#include "SelectThread.h"
#include "RecvThread.h"
#include "SendThread.h"
#include "TcpEvtThread.h"

#include "Select.h"
#include "RecvDataHandler.h"
#include "SendDataHandler.h"

#include "TcpConnectionMgr.h"
#include "TcpServiceMgr.h"
#include "TcpEvtMgr.h"
#include "SocketDataMgr.h"

#include "Timer.h"


namespace tc
{
	// tcp comm
	class TcpCommu
	{
	private:
		TcpCommu();

	private:
		static SelectThread selectThread;			// select�̶߳���
		static RecvThread recvThread;				// �������̶߳���
		static SendThread sendThread;				// �������̶߳���
		static TcpEvtThread tcpEvtThread;			// tcp�¼��߳�

		static Select select;						// select����
		static RecvDataHandler recvHandler;			// �����ݴ������
		static SendDataHandler sendHandler;			// �����ݴ������
		
		static SocketDataMgr socketDataMgr;			// socket���ݹ������
		static TcpConnectionMgr tcpConnMgr;			// tcp���ӹ������
		static TcpServiceMgr tcpServiceMgr;			// tcp����������
		static TcpEvtMgr tcpEvtMgr;					// tcp�¼��������

		static Timer t;								// timer for close socket

	public:
		~TcpCommu();

		//************************************
		// Method:    ��ʼ��
		//************************************
		static void Init();

		//************************************
		// Method:    �˳�
		//************************************
		static void Exit();

		//************************************
		// Method:    �Ƿ���Ҫ�˳�
		//************************************
		static bool IsExited();

		//************************************
		// Method:    ��ȡselect�̶߳���
		//************************************
		static SelectThread* GetSelectThread();

		//************************************
		// Method:    ��ȡ�������̶߳���
		//************************************
		static RecvThread* GetRecvThread();

		//************************************
		// Method:    ��ȡ�������̶߳���
		//************************************
		static SendThread* GetSendThread();

		//************************************
		// Method:    ��ȡtcp�¼��̶߳���
		//************************************
		static TcpEvtThread* GetTcpEvtThread();

		//************************************
		// Method:    ��ȡselect����
		//************************************
		static Select* GetSelect();

		//************************************
		// Method:    ��ȡTcpConnectionMgr����
		//************************************
		static TcpConnectionMgr* GetTcpConnectionMgr();

		//************************************
		// Method:    ��ȡtcp����������
		//************************************
		static TcpServiceMgr* GetTcpServiceMgr();

		//************************************
		// Method:    ��ȡtcp�¼��������
		//************************************
		static TcpEvtMgr* GetTcpEvtMgr();

		//************************************
		// Method:    ��ȡsocket���ݹ������
		//************************************
		static SocketDataMgr* GetSocketDataMgr();

		//************************************
		// Method:    ��ȡ�����ݴ������
		//************************************
		static RecvDataHandler* GetRecvHandler();

		//************************************
		// Method:    ��ȡ�����ݴ������
		//************************************
		static SendDataHandler* GetSendHandler();
	};
}