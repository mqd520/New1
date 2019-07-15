#pragma once
#include "SocketTool.h"
#include "TcpService.h"
#include "timer.h"

namespace tc
{
	class TimerCallback;

	// tcp�ͻ�����
	class TcpClient : public TcpService
	{
	public:
		TcpClient(string ip = "", int port = 0);
		virtual ~TcpClient();

	protected:
		bool bInited;			// �Ƿ��ѳ�ʼ��
		bool bIsConnecting;		// �Ƿ����ڽ�������
		bool bIsConnected;		// �Ƿ���������
		bool bIsReconnect;		// �Ƿ���Ҫ�Զ���������
		int nTimeSpan;			// �Զ��������ʱ��
		Timer t;				// ��ʱ��

	private:
		//************************************
		// Method:    ��ʱ���¼�����
		// Parameter: ��ʱ������
		// Parameter: ����
		// Parameter: void * pParam1
		// Parameter: void * pParam2
		//************************************
		void OnTimer(Timer* pTimer, int count, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ��ʼ��
		//************************************
		void Init();

		//************************************
		// Method:    ���ӷ����
		//************************************
		void ConnectServer();

	protected:
		//************************************
		// Method:    ���ӷ��������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnConnectSrvCpl(ConnectSrvCplEvt* pEvt) override;

		//************************************
		// Method:    ���ӶϿ��¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

	public:
		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit() override;

		//************************************
		// Method:    �����Զ�������Ϣ
		// Parameter: �Ƿ��Զ�����
		// Parameter: ���ʱ��(ms)
		//************************************
		virtual void SetAutoReconnect(bool b = true, int time = TC_ReconnectTime);

		//************************************
		// Method:    ���ӷ����
		//************************************
		virtual void Connect();

		//************************************
		// Method:    �ر�����
		// Parameter: b:	�Ƿ�������ӹر��¼�
		//************************************
		virtual void Close(bool b = true);

		//************************************
		// Method:    ����������Ϣ
		// Parameter: ip:	�����IP
		// Parameter: port:	����˶˿�
		//************************************
		virtual void SetConnectInfo(string ip, int port);

		//************************************
		// Method:    ��Զ˷�������
		// Parameter: ������ָ��
		// Parameter: �������ֽڳ���
		//************************************
		virtual void Send(BYTE* pBuf, int len);
	};
}