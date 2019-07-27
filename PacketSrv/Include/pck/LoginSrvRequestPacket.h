#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// Login server request
	class LoginSrvRequestPacket : public Packet
	{
	public:
		LoginSrvRequestPacket();

	public:
		BYTE		cbCurrentServerType;	// current server type, 1 byte
		BYTE		cbRequestServerID;		// request server Id, 1 byte
		BYTE		cbKeepAlive;			// KeepAlive value, 1 byte
		INT32		nVersion;				// Version, 4 byte
		string		strGuid;				// GUID

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