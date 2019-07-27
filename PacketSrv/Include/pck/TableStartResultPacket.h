#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// Start table result
	class TableStartResultPacket : public Packet
	{
	public:
		TableStartResultPacket();

	public:
		INT32 nResult;	// start table result,  > 0: success, 0: fail

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