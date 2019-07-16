#pragma once

#include "IGPacketSrvServer.h"

#include "ws/WSProtocolHandleMgr.h"
using namespace ws;


namespace pck
{
	// IGPacketSrvWSServer
	class IGPacketSrvWSServer : public IGPacketSrvServer
	{
	public:
		//************************************
		// Method:    Constructor
		// Parameter: string ip
		// Parameter: int port
		// Parameter: EServerType localType
		// Parameter: bool bRecvPwd: is recv client pwd
		//************************************
		IGPacketSrvWSServer(
			string ip = "", int port = 0,
			EServerType localType = EServerType::None,
			bool bRecvPwd = true);

	private:
		WSProtocolHandleMgr wsHandleMgr;	// WSProtocolHandleMgr obj

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

		//************************************
		// Method:    Connection disconnect evt handle
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
}