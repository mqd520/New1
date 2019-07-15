#include "stdafx.h"
#include "Include/pck/PacketSessionMgr.h"
#include "Include/pck/PacketSession.h"

namespace pck
{
	PacketSessionMgr::PacketSessionMgr()
	{

	}

	PacketSessionMgr::~PacketSessionMgr()
	{

	}

	TcpSession* PacketSessionMgr::CreateSession()
	{
		return new PacketSession();
	}

	//void PacketSessionMgr::Add(
	//	EServerType localType /*= EServerType::None*/, EServerType peertType /*= EServerType::None*/,
	//	string peerIp /*= ""*/, int peerPort /*= 0*/, int clientId /*= 0*/, string localIp /*= ""*/, int localPort /*= 0*/)
	//{
	//	TcpSession* pSession = __super::Add(peerIp, peerPort, clientId);

	//	PacketSession* pSession1 = (PacketSession*)pSession;
	//	pSession1->localServerType = localType;
	//	pSession1->peerServerType = peertType;
	//}
}