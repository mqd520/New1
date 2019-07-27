#pragma once

// Common
#include "KeepAlivePacket.h"
#include "LoginSrvRequestPacket.h"
#include "LoginSrvResultPacket.h"

// Center
#include "ServerListenPacket.h"
#include "ServerListenExPacket.h"

// Game
#include "StartTablePacket.h"
#include "TableStartResultPacket.h"


extern const pck::EPacketCmd _vecPacketCmds[];		// packet cmd vector
extern const int _nCmdCount;						// packet cmd count