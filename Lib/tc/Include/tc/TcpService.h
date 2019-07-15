#pragma once
#include "Def.h"
#include "Thread.h"
#include "SocketAPI.h"
#include "TcpEvt.h"
#include "RecvNewConnEvt.h"
#include "ConnDisconnectEvt.h"
#include "RecvPeerDataEvt.h"
#include "ConnectSrvCplEvt.h"
#include "SessionMgr.h"

namespace tc
{
	// tcp����������
	class TcpService
	{
	public:
		TcpService(string ip = "", int port = 0, ETcpSrvType type = ETcpSrvType::None);
		virtual ~TcpService();

	protected:
		SOCKET socket;				// ������socket
		string strIP;				// socket�����ķ����IP
		int nPort;					// socket�����ķ���˶˿�
		Fun2 fun;					// tcp�¼��ص�����ָ��
		void* pParam1;				// �¼����Ӳ���1
		void* pParam2;				// �¼����Ӳ���2
		ETcpSrvType tcpSrvType;		// tcp srv type
		SessionMgr* pSessionMgr;	// session mgr

	protected:
		friend class TcpEvtMgr;

		//************************************
		// Method:    tcp�¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnTcpEvt(TcpEvt* pEvt);

		//************************************
		// Method:    �յ��������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt);

		//************************************
		// Method:    ���ӶϿ��¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt);

		//************************************
		// Method:    �յ��Զ������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt);

		//************************************
		// Method:    ���ӷ��������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnConnectSrvCpl(ConnectSrvCplEvt* pEvt);

		//************************************
		// Method:    �ɷ�tcp�¼�
		// Parameter: tcp�¼�
		//************************************
		virtual void DispatchTcpEvt(TcpEvt* pEvt);

		//************************************
		// Method:    ��Զ˷�������
		// Parameter: ������ָ��
		// Parameter: �������ֽڳ���
		//************************************
		virtual void SendData(SOCKET socket, BYTE* pBuf, int len);

		//************************************
		// Method:    �ر�tcp����
		// Parameter: socket
		// Parameter: �Ƿ�������ӹر��¼�
		//************************************
		virtual void CloseConnection(SOCKET socket, bool b = true);

		//************************************
		// Method:    set session mgr to this class
		// Parameter: SessionMgr * pSessionMgr
		//************************************
		virtual void SetSessionMgr(SessionMgr* pSessionMgr);

	public:
		//************************************
		// Method:    ��ʼ��
		//************************************
		virtual void Init();

		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit();

		//************************************
		// Method:    ��ȡtcp srv type
		//************************************
		virtual ETcpSrvType GetTcpSrvType();

		//************************************
		// Method:    ��ȡ������socket
		//************************************
		virtual SOCKET GetSocket();

		//************************************
		// Method:    ��ȡ�����ķ����IP
		//************************************
		virtual string GetIP();

		//************************************
		// Method:    ��ȡ�����ķ���˶˿�
		//************************************
		virtual int GetPort();

		//************************************
		// Method:    ע��tcp�¼��ص�����
		// Parameter: lpCallback:	�ص�����
		// Parameter: pParam1:		���Ӳ���1
		// Parameter: pParam1:		���Ӳ���2
		//************************************
		virtual void RegTcpEventCallback(Fun2 fun, void* pParam1 = NULL, void* pParam2 = NULL);

		//************************************
		// Method:    ��ȡSessionMgr
		//************************************
		virtual SessionMgr* GetSessionMgr();
	};
}