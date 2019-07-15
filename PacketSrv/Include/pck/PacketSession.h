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
		// Method:    ���캯��(PacketSession)
		// Parameter: EServerType localServerType:	���ط���������
		// Parameter: EServerType peerServerType:	�Զ˷���������
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
		EServerType localServerType;		// ���ط���������
		EServerType peerServerType;			// �Զ˷���������
	};
}