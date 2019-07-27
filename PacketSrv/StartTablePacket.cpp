#include "stdafx.h"
#include "Include/pck/StartTablePacket.h"

namespace pck
{
	StartTablePacket::StartTablePacket() :
		Packet((int)EPacketCmd::StartTable)
	{

	}

	int StartTablePacket::GetLen()
	{
		int len = 0;

		len += sizeof(INT32);

		return len;
	}

	void StartTablePacket::Read(NetworkStreamRead& ns)
	{
		nTableId = ns.ReadInt32();
	}

	void StartTablePacket::Write(NetworkStreamWrite& ns)
	{
		ns.WriteInt32(nTableId);
	}
}