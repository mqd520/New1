#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// packet tool
	class PacketTool final
	{
	private:
		PacketTool();

	public:
		//************************************
		// Method:    cmd�Ƿ����
		//************************************
		static bool IsCmdValid(EPacketCmd cmd);

		//************************************
		// Method:    ������
		// Parameter: cmd:	������
		//************************************
		static Packet* GetPacket(EPacketCmd cmd);
	};
}