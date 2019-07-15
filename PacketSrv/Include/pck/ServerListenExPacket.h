#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// ��������չ������Ϣ��
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