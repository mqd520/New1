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
	// Method:    登录服务端请求事件处理
	// Parameter: data: packet data
	//************************************
	virtual bool OnLoginSrvRequest(PacketData& data) override;

	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;

	//************************************
	// Method:    包处理
	// Parameter: PacketData & pd
	//************************************
	virtual void OnProcessPck(PacketData& pd) override;

public:
	//************************************
	// Method:    初始化
	//************************************
	void Init();

	//************************************
	// Method:    初始化
	//************************************
	void Exit() override;

	//************************************
	// Method:    关闭客户端
	// Parameter: int clientId
	// Parameter: bool b
	//************************************
	void CloseClient(int clientId, bool b = true) override;
};