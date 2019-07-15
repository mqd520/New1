#include "stdafx.h"
#include "Include/pck/PacketSession.h"

namespace pck
{
	PacketSession::PacketSession(
		EServerType localServerType /*= EServerType::None*/, EServerType peerServerType /*= EServerType::None*/,
		string peerIp /*= ""*/, int peerPort /*= 0*/, int clientId /*= 0*/, string localIp /*= ""*/, int localPort /*= 0*/) :

		TcpSession(peerIp, peerPort, clientId, localIp, localPort)
	{

	}

	PacketSession::~PacketSession()
	{

	}
}