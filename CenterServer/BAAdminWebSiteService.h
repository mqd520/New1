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
	// Method:    Recv new connection evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

	//************************************
	// Method:    Recv peer data evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

public:
	//************************************
	// Method:    Init
	//************************************
	virtual void Init() override;
};