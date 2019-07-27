#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// Sever extend listen
	class ServerListenExPacket : public Packet
	{
	public:
		ServerListenExPacket();

	public:
		UINT32 IP;
		string strIP1;
		UINT16 Port;
		UINT16 H5Port;
		string strConnPwd;
		BYTE ServerType;
		BYTE bInternal;
		UINT16 H5Port1;

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