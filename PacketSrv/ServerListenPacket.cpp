#include "stdafx.h"
#include "Include/pck/ServerListenPacket.h"

namespace pck
{
	ServerListenPacket::ServerListenPacket() :
		Packet((int)EPacketCmd::ServerListen),
		nIP(0),
		nIP1(0),
		nPort(0),
		nH5Port(0),
		strConnPwd(""),
		ServerType(0),
		bInternal(0),
		strDomainName(""),
		nWssPort(0)
	{

	}

	int ServerListenPacket::GetLen()
	{
		int len = 0;

		len += sizeof(UINT32);
		len += sizeof(UINT32);
		len += sizeof(UINT16);
		len += sizeof(UINT16);
		len += sizeof(int) + strConnPwd.size() + 1;
		len += sizeof(BYTE);
		len += sizeof(BYTE);
		len += sizeof(INT32) + strDomainName.size() + 1;
		len += sizeof(UINT32);

		return len;
	}

	void ServerListenPacket::Read(NetworkStreamRead& ns)
	{
		nIP = ns.ReadUInt32();
		nIP1 = ns.ReadUInt32();
		nPort = ns.ReadUInt16();
		nH5Port = ns.ReadUInt16();
		strConnPwd = ns.ReadGB2312Str1();
		ServerType = ns.ReadByte();
		bInternal = ns.ReadByte();
		strDomainName = ns.ReadGB2312Str1();
		nWssPort = ns.ReadUInt32();
	}

	void ServerListenPacket::Write(NetworkStreamWrite& ns)
	{
		ns.WriteUInt32(nIP);
		ns.WriteUInt32(nIP1);
		ns.WriteUInt16(nPort);
		ns.WriteUInt16(nH5Port);
		ns.WriteGB2312Str(strConnPwd);
		ns.WriteByte(ServerType);
		ns.WriteByte(bInternal);
		ns.WriteGB2312Str(strDomainName);
		ns.WriteUInt32(nWssPort);
	}
}