#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// 服务器扩展监听信息包
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
		// Method:    获取包长度(不含包头)
		//************************************
		virtual int GetLen() override;

		//************************************
		// Method:    从流中读取数据到包中
		// Parameter: ns:	只读网络流对象
		//************************************
		virtual void Read(NetworkStreamRead& ns) override;

		//************************************
		// Method:    向流中写入数据
		// Parameter: ns:	只写网络流对象
		//************************************
		virtual void Write(NetworkStreamWrite& ns) override;
	};
}