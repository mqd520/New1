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
	// Method:    �յ��������¼�����
	// Parameter: pEvt: tcp�¼�
	//************************************
	virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

	//************************************
	// Method:    �յ��Զ������¼�����
	// Parameter: pEvt: tcp�¼�
	//************************************
	virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;

public:
	//************************************
	// Method:    Init
	//************************************
	virtual void Init() override;
};