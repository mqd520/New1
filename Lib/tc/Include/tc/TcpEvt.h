#pragma once
#include "SocketTool.h"
#include "Def.h"

namespace tc
{
	class TcpService;

	// tcp�����¼�����
	class TcpEvt
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: ������tcp�������
		// Parameter: ���������ڷ���(����)���ݵ�socket
		//************************************
		TcpEvt(TcpService* pSrv, SOCKET sendrecv = NULL);
		virtual ~TcpEvt();

	protected:
		TcpService* pTcpSrv;	// tcp�������
		SOCKET socket;			// ���������ڷ���(����)���ݵ�socket
		ETcpEvtType evtType;	// �¼�����
		int socketId;			// socket id
		string strPeerIp;		// peer ip
		int nPeerPort;			// peer port

	public:
		//************************************
		// Method:    ��ȡ�¼�����
		//************************************
		virtual ETcpEvtType GetEvtType();

		//************************************
		// Method:    ��ȡtcp�������
		//************************************
		virtual TcpService* GetTcpSrv();

		//************************************
		// Method:    ��ȡ���ڷ���(����)���ݵ�socket id
		//************************************
		virtual int GetSendRecvSocketId();

		//************************************
		// Method:    ��ȡsocket
		//************************************
		virtual SOCKET GetSendRecvSocket();

		//************************************
		// Method:    ��ȡ�Զ�ip
		//************************************
		virtual string GetPeerIp();

		//************************************
		// Method:    ��ȡ�Զ�port
		//************************************
		virtual int GetPeerPort();
	};
}