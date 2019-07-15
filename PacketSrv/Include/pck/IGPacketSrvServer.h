#pragma once
#include "Def.h"
#include "IGPacketSrv.h"
#include "ServerSessionMgr.h"
#include "PacketCmd.h"

#include "tc/TcpServer.h"

namespace pck
{
	// IGPacketSrvServer 
	class IGPacketSrvServer : public TcpServer, public IGPacketSrv
	{
	public:
		IGPacketSrvServer(
			string ip = "", int port = 0,
			EServerType localType = EServerType::None,
			bool bRecvPwd = true);
		virtual ~IGPacketSrvServer();

	protected:
		bool bRecvPwd;				// �Ƿ���Ҫ���ܿͻ�������
		int nCurClientId;			// ��ǰ�Ự�Ŀͻ���Id
		ServerSessionMgr serverSessionMgr;		// server session mgr

	protected:
		friend class ServerSession;

		//************************************
		// Method:    �յ��������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

		//************************************
		// Method:    �յ��Զ������¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

		//************************************
		// Method:    ���ӶϿ��¼�����
		// Parameter: pEvt: tcp�¼�
		//************************************
		virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

		//************************************
		// Method:    Ԥ�������
		// Parameter: data:	������
		//************************************
		virtual void PreProcessPck(PacketData& data) override;

		//************************************
		// Method:    ��¼����������¼�����
		// Returns:   �Ƿ���Ϊ��¼�ɹ� (��: ������LoginSrvResultPacket��, ��: �����Ͳ��ر�����)
		// Parameter: data:	������
		//************************************
		virtual bool OnLoginSrvRequest(PacketData& data);

		//************************************
		// Method:    �����¼����˴�����
		// Parameter: PacketData & data
		// Parameter: success: �Ƿ�ɹ�
		//************************************
		virtual void ProcessLoginSrvResult(PacketData& data, bool success = true);

		//************************************
		// Method:    ���͵�¼����˽����
		// Parameter: int clientId
		//************************************
		virtual void SendLoginSrvResultPck(int clientId);

		//************************************
		// Method:    session�ر��¼�����
		// Parameter: int clientId
		//************************************
		virtual void OnSessionClose(int clientId);
		
		//************************************
		// Method:    ����������
		//************************************
		virtual void SendKeepAlive(int clientId = 0);

		//************************************
		// Method:    ��ʧ�������¼�����
		// Parameter: int clientId
		// Parameter: count:	������ʧ����
		// Parameter: b:	�Ƿ��ѳ�������������
		//************************************
		virtual void OnMissKeepAlive(int clientId, int count, bool b = true);

	public:
		//************************************
		// Method:    ����
		// Parameter: ������
		// Parameter: �ͻ���id
		//************************************
		virtual void SendPck(Packet& pck, int clientId);

		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit() override;

		//************************************
		// Method:    �رտͻ���
		// Parameter: int clientId
		// Parameter: bool b
		//************************************
		void CloseClient(int clientId, bool b = true) override;
	};
}