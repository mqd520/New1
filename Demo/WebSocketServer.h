#pragma once

#include "tc/TcpServer.h"
using namespace tc;

#include "ws/WSProtocolHandleMgr.h"
using namespace ws;


class WebSocketServer : public TcpServer
{
public:
	WebSocketServer(string ip = "", int port = 0);
	~WebSocketServer();

private:
	WSProtocolHandleMgr wsHandleMgr;	// WSProtocolHandleMgr obj

protected:
	//************************************
	// Method:    Recv new connection evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnRecvNewConnection(RecvNewConnEvt* pEvt) override;

	//************************************
	// Method:    Recv peer data evt handler
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnRecvPeerData(RecvPeerDataEvt* pEvt) override;
	
	//************************************
	// Method:    Conn disconnect evt handle
	// Parameter: pEvt: tcp evt
	//************************************
	virtual void OnConnDisconnect(ConnDisconnectEvt* pEvt) override;

	//************************************
	// Method:    Send buf
	// Parameter: socket:	socket
	// Parameter: pBuf:		buf
	// Parameter: len:		buf length
	//************************************
	virtual void SendData(SOCKET socket, BYTE* pBuf, int len) override;

public:
	//************************************
	// Method:    Close client
	// Parameter: int clientId
	// Parameter: bool b
	//************************************
	void CloseClient(int clientId, bool b = true) override;
};