#include "stdafx.h"
#include "Include/pck/ServerListenExPacket.h"

namespace pck
{
	ServerListenExPacket::ServerListenExPacket() :
		Packet((int)EPacketCmd::ServerListenEx)
	{

	}

	int ServerListenExPacket::GetLen()
	{
		int len = 0;

		len += sizeof(UINT32);
		len += sizeof(int) + strIP1.size() + 1;
		len += sizeof(UINT16);
		len += sizeof(UINT16);
		len += sizeof(int) + strConnPwd.size() + 1;
		len += sizeof(BYTE);
		len += sizeof(BYTE);
		len += sizeof(UINT16);

		return len;
	}

	void ServerListenExPacket::Read(NetworkStreamRead& ns)
	{
		IP = ns.ReadUInt32();
		strIP1 = ns.ReadGB2312Str1();
		Port = ns.ReadUInt16();
		H5Port = ns.ReadUInt16();
		strConnPwd = ns.ReadGB2312Str1();
		ServerType = ns.ReadByte();
		bInternal = ns.ReadByte();
		H5Port1 = ns.ReadUInt16();
	}

	void ServerListenExPacket::Write(NetworkStreamWrite& ns)
	{
		ns.WriteUInt32(IP);
		ns.WriteGB2312Str(strIP1);
		ns.WriteUInt16(Port);
		ns.WriteUInt16(H5Port);
		ns.WriteGB2312Str(strConnPwd);
		ns.WriteByte(ServerType);
		ns.WriteByte(bInternal);
		ns.WriteUInt16(H5Port1);
	}
}