#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// ������
	class KeepAlivePacket : public Packet
	{
	public:
		KeepAlivePacket();

	public:
		BYTE cbKeepAlive;		// cbKeepAlive

	public:
		//************************************
		// Method:    ��ȡ������(������ͷ)
		//************************************
		virtual int GetLen() override;

		//************************************
		// Method:    �����ж�ȡ���ݵ�����
		// Parameter: ns:	ֻ������������
		//************************************
		virtual void Read(NetworkStreamRead& ns) override;

		//************************************
		// Method:    ������д������
		// Parameter: ns:	ֻд����������
		//************************************
		virtual void Write(NetworkStreamWrite& ns) override;
	};
}