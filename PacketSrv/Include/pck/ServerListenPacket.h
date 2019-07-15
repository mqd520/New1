#pragma once
#include "PacketCmd.h"

#include "tc/Packet.h"
using namespace tc;

namespace pck
{
	// 服务器监听信息包
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
		string strDomainName;	// 域名, 仅对于大厅服务
		UINT32 nWssPort;		// wss port

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