#pragma once
#include "SocketAPI.h"
#include "TcpService.h"
#include "Def.h"

using namespace std;

namespace tc
{
	// tcp���ӻỰ��
	class TcpConnection
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: tcp�������
		// Parameter: ���ڷ���(����)���ݵ�socket
		// Parameter: �Ƿ���������select
		//************************************
		TcpConnection(TcpService* pSrv, SOCKET sendrecv, bool bEnable = true);
		~TcpConnection();

	protected:
		TcpService* pTcpSrv;	// tcp�������
		SOCKET sendrecvSocket;	// ���ڷ���(����)���ݵ�socket

	public:
		//************************************
		// Method:    ��ȡ���ڷ���(����)���ݵ�socket
		// Returns:   socket
		//************************************
		SOCKET GetSendRecvSocket();

		//************************************
		// Method:    ��ȡ������tcp�������
		// Returns:   tcp�������
		//************************************
		TcpService* GetTcpService();

		//************************************
		// Method:    ��������
		// Parameter: ������ָ��
		// Parameter: �������ֽڳ���
		//************************************
		void SendData(BYTE* pBuf, int len);

		//************************************
		// Method:    �ر�tcp����
		// Parameter: b:	�Ƿ��������ӶϿ��¼�, Ĭ��: false
		//************************************
		void Close(bool b = false);

		//************************************
		// Method:    �յ��Զ������¼�����
		// Parameter: pBuf:		������ָ��
		// Parameter: len:		������ָ�볤��
		//************************************
		virtual void OnRecvPeerData(BYTE* pBuf, int len);

		//************************************
		// Method:    ���ӶϿ��¼�����
		// Parameter: reason:	���ӶϿ�ԭ��
		// Parameter: b:	�Ƿ��������ӶϿ��¼�, Ĭ��: true
		//************************************
		virtual void OnConnDisconnect(EDisconnReason reason, bool b = true);

		//************************************
		// Method:    ��������¼�����
		//************************************
		virtual void OnNetError();
	};
}