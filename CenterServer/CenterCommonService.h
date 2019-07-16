#pragma once

#include "pck/IGPacketSrvServer.h"
using namespace pck;



class CenterService;

// center common service
class CenterCommonService : public IGPacketSrvServer
{
public:
	CenterCommonService(string ip = "", int port = 0);
	virtual ~CenterCommonService();

protected:
	CenterService* pCenterSrv;	// ���ķ���

protected:
	//************************************
	// Method:    Recv new connection evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

	//************************************
	// Method:    Connection disconnect evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

	//************************************
	// Method:    ��¼����������¼�����
	// Parameter: data: packet data
	//************************************
	virtual bool OnLoginSrvRequest(PacketData& data) override;

	//************************************
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;

	//************************************
	// Method:    ������
	// Parameter: PacketData & pd
	//************************************
	virtual void OnProcessPck(PacketData& pd) override;

	//************************************
	// Method:    ServerListenPacket���������
	// Parameter: PacketData & pd
	//************************************
	virtual void OnServerListen(PacketData& pd);

public:
	//************************************
	// Method:    ��ʼ��
	//************************************
	void Init();

	//************************************
	// Method:    ��ʼ��
	//************************************
	void Exit() override;

	//************************************
	// Method:    �رտͻ���
	// Parameter: int clientId
	// Parameter: bool b
	//************************************
	void CloseClient(int clientId, bool b = true) override;

	//************************************
	// Method:    �����пͻ��˷��Ͱ�
	// Parameter: Packet & pck
	//************************************
	void SendPck2AllClients(Packet& pck);
};