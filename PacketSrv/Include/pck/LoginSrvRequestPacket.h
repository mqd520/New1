#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// ��¼����������
	class LoginSrvRequestPacket : public Packet
	{
	public:
		LoginSrvRequestPacket();

	public:
		BYTE		cbCurrentServerType;	// ��ǰ��������, 1���ֽ�
		BYTE		cbRequestServerID;		// ����ķ�����id, 1���ֽ�
		BYTE		cbKeepAlive;			// ����ֵ, 1���ֽ�
		INT32		nVersion;				// �汾, 4���ֽ�
		string		strGuid;				// GUID

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