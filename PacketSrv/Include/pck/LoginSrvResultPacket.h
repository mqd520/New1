#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// ��¼����˽����
	class LoginSrvResultPacket : public Packet
	{
	public:
		LoginSrvResultPacket();

	public:
		BYTE		cbVerifyCode;	// code
		INT32		nServerID;		// server id

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