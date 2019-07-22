#pragma once

#include "pck/IGPacketSrvServer.h"
using namespace pck;


class BaccratService;

// Game center service
class GameCenterService : public IGPacketSrvServer
{
public:
	GameCenterService(string ip = "", int port = 0);
	virtual ~GameCenterService();

protected:
	BaccratService* pBaccratSrv;	// Baccrat Service

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
};