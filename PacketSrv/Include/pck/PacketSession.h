#pragma once

#include "Def.h"

#include "tc/TcpSession.h"
using namespace tc;

namespace pck
{
	// packet session
	class PacketSession : public TcpSession
	{
	public:
		//************************************
		// Method:    构造函数(PacketSession)
		// Parameter: EServerType localServerType:	本地服务器类型
		// Parameter: EServerType peerServerType:	对端服务器类型
		// Parameter: string peerIp
		// Parameter: int peerPort
		// Parameter: int clientId
		// Parameter: string localIp
		// Parameter: int localPort
		//************************************
		PacketSession(
			EServerType localServerType = EServerType::None, EServerType peerServerType = EServerType::None,
			string peerIp = "", int peerPort = 0, int clientId = 0, string localIp = "", int localPort = 0);
		virtual ~PacketSession();

	public:
		EServerType localServerType;		// 本地服务器类型
		EServerType peerServerType;			// 对端服务器类型
	};
}