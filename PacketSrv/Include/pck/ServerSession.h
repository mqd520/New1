#pragma once

#include "tc/TcpEvt.h"
#include "tc/RecvPeerDataEvt.h"
#include "tc/ConnDisconnectEvt.h"
#include "tc/Timer.h"
#include "tc/KeepAliveServer.h"
using namespace tc;

namespace pck
{
	// server session
	class ServerSession : public KeepAliveServer
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: int clientId
		// Parameter: void* pObj:	IGPacketSrvServer����
		// Parameter: recvPwd:	�Ƿ���Ҫ��֤�ͻ�������
		//************************************
		ServerSession(int clientId, void* pObj, bool recvPwd = true);
		virtual ~ServerSession();

	protected:
		int nClientId;		// �ͻ���id
		string strIp;		// �Զ�ip
		int nPort;			// �Զ�port
		bool bRecvPwd;		// �Ƿ���Ҫ��֤�ͻ�������
		bool bVertified;	// �Ƿ�����֤�ͻ�������
		Timer tVertify;		// ��֤�ͻ�������͵�¼���������ʱ��
		void* pObj;			// IGPacketSrvServer����

	protected:
		//************************************
		// Method:    ��ʱ���¼�����
		// Parameter: ��ʱ������
		// Parameter: ����
		// Parameter: void * pParam1
		// Parameter: void * pParam2
		//************************************
		void OnTimerVertify(Timer* pTimer, int count, void* pParam1 = NULL, void* pParam2 = NULL);

	public:
		//************************************
		// Method:    ����PacketSrv����
		// Parameter: void pObj:	TcpService����
		//************************************
		void AttachObj(void* pObj);

		//************************************
		// Method:    �յ��Զ������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		bool OnRecvPeerData(RecvPeerDataEvt* pEvt);

		//************************************
		// Method:    ���ӶϿ��¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		void OnConnDisconnect(ConnDisconnectEvt* pEvt);

		// Method:    ��¼����������¼�����
		// Parameter: data:	������
		// Parameter: b:	��֤�Ƿ�ͨ��
		//************************************
		void OnLoginSrvRequest(PacketData& data, bool b = true);

		//************************************
		// Method:    ����������
		//************************************
		virtual void SendKeepAlive(int clientId = 0) override;

		//************************************
		// Method:    ��ʧ�������¼�����
		// Parameter: count:	������ʧ����
		// Parameter: b:	�Ƿ��ѳ�������������
		//************************************
		virtual void OnMissKeepAlive(int count, bool b = true) override;

		//************************************
		// Method:    �������¼�����
		//************************************
		void OnRecvKeepAlive();

		//************************************
		// Method:    ��ȡclient id
		//************************************
		int GetClientId() const;

		//************************************
		// Method:    ��ȡip
		//************************************
		string GetIp() const;

		//************************************
		// Method:    ��ȡport
		//************************************
		int GetPort() const;

		//************************************
		// Method:    �Ƿ�����֤ͨ��
		//************************************
		bool IsVertified();

		//************************************
		// Method:    �ر�
		//************************************
		void Close();
	};
}