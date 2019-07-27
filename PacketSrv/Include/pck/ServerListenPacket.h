#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// Server listen
	class ServerListenPacket : public Packet
	{
	public:
		ServerListenPacket();

	public:
		UINT32 nIP;
		UINT32 nIP1;
		UINT16 nPort;
		UINT16 nH5Port;
		string strConnPwd;
		BYTE ServerType;
		BYTE bInternal;
		string strDomainName;	// domain, only for plaza server
		UINT32 nWssPort;		// wss port

	public:
		//************************************
		// Method:    Get packet length(Not include packet head)
		//************************************
		virtual int GetLen() override;

		//************************************
		// Method:    read data from stream
		// Parameter: ns:	readonly stream obj
		//************************************
		virtual void Read(NetworkStreamRead& ns) override;

		//************************************
		// Method:    write data to stream
		// Parameter: ns:	writeonly stream obj
		//************************************
		virtual void Write(NetworkStreamWrite& ns) override;
	};
}