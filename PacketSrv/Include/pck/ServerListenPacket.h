#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// ������������Ϣ��
	class ServerListenPacket : public Packet
	{
	public:
		ServerListenPacket();

	public:
		UINT32 nIP;
		UINT32 nIP1;
		UINT16 nPort;
		UINT16 nH5Port;
		string strConnPwd;
		BYTE ServerType;
		BYTE bInternal;
		string strDomainName;	// ����, �����ڴ�������
		UINT32 nWssPort;		// wss port

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