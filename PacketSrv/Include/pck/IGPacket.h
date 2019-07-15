#pragma once

#include "KeepAlivePacket.h"
#include "LoginSrvRequestPacket.h"
#include "LoginSrvResultPacket.h"

#include "ServerListenPacket.h"
#include "ServerListenExPacket.h"


extern const pck::EPacketCmd _vecPacketCmds[];		// packet cmd vector
extern const int _nCmdCount;						// packet cmd count