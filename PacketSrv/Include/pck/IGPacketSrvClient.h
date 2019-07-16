#pragma once
#include "Def.h"
#include "IGPacketSrv.h"

#include "tc/TcpClient.h"
#include "tc/KeepAliveClient.h"
using namespace tc;

namespace pck
{
	// ig��ͨ�ŷ���
	class IGPacketSrvClient : public TcpClient, public IGPacketSrv, public KeepAliveClient
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: EServerType localType:	���ط���������
		// Parameter: EServerType peerType:		�Զ˷���������
		// Parameter: string ip:	ip
		// Parameter: int port:		port
		// Parameter: bool bSendPwd:	�Ƿ���Ҫ�����˷�������
		//************************************
		IGPacketSrvClient(
			string ip = "", int port = 0,
			EServerType localType = EServerType::None,
			EServerType peerType = EServerType::None, bool bSendPwd = true);
		virtual ~IGPacketSrvClient();

	protected:
		bool bSendPwd;				// �Ƿ���Ҫ�����˷�������
		EServerType peerType;		// �Զ˷���������

	protected:
		//************************************
		// Method:    ���ӷ��������¼�����
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnConnectSrvCpl(ConnectSrvCplEvt* pEvt) override;

		//************************************
		// Method:    Recv peer data evt handle
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

		//************************************
		// Method:    Connection disconnect evt handle
		// Parameter: pEvt: tcp evt
		//************************************
		virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

		//************************************
		// Method:    Preprocess packet
		// Parameter: data: packet data
		//************************************
		virtual void PreProcessPck(PacketData& data) override;

		//************************************
		// Method:    �����˷�������
		//************************************
		virtual void SendPwd();

		//************************************
		// Method:    ���͵�¼����������
		//************************************
		virtual void SendLoginSrvRequestPck();

		//************************************
		// Method:    ��¼����ɹ��¼�����
		//************************************
		virtual void OnLoginSrvSuccess();

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

	public:
		//************************************
		// Method:    ����
		// Parameter: Packet & pck
		//************************************
		virtual void SendPck(Packet& pck);

		//************************************
		// Method:    ��ȡ�Զ˷���������
		// Returns:   pck::EServerType
		//************************************
		virtual EServerType GetPeerServerType();

		//************************************
		// Method:    �˳�
		//************************************
		virtual void Exit() override;
	};
}