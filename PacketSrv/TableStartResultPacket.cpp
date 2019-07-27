#include "stdafx.h"
#include "Include/pck/TableStartResultPacket.h"

namespace pck
{
	TableStartResultPacket::TableStartResultPacket() :
		Packet((int)EPacketCmd::StartTableResult)
	{

	}

	int TableStartResultPacket::GetLen()
	{
		int len = 0;

		len += sizeof(INT32);

		return len;
	}

	void TableStartResultPacket::Read(NetworkStreamRead& ns)
	{
		nResult = ns.ReadInt32();
	}

	void TableStartResultPacket::Write(NetworkStreamWrite& ns)
	{
		ns.WriteInt32(nResult);
	}
}