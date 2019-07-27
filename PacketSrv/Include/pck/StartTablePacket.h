#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// Start table
	class StartTablePacket : public Packet
	{
	public:
		StartTablePacket();

	public:
		INT32 nTableId;

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