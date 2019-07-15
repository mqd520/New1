#pragma once

#include "Def.h"

#include "tc/SessionMgr.h"
using namespace tc;

namespace pck
{
	// packet session mgr
	class PacketSessionMgr : public SessionMgr
	{
	public:
		PacketSessionMgr();
		virtual ~PacketSessionMgr();

	public:
		virtual TcpSession* CreateSession() override;
	};
}