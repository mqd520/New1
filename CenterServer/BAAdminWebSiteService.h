#pragma once

#include "tc/TcpServer.h"
using namespace tc;


// backstage admin website service
class BAAdminWebSiteService : public TcpServer
{
public:
	BAAdminWebSiteService(string ip = "", int port = 0);
	~BAAdminWebSiteService();

protected:
	//************************************
	// Method:    收到新连接事件处理
	// Parameter: pEvt: tcp事件
	//************************************
	virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

	//************************************
	// Method:    收到对端数据事件处理
	// Parameter: pEvt: tcp事件
	//************************************
	virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

public:
	//************************************
	// Method:    Init
	//************************************
	virtual void Init() override;
};