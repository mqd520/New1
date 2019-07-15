#include "stdafx.h"
#include "Include/pck/IGPacket.h"
#include "Include/pck/PacketCmd.h"


// packet cmd vector
const pck::EPacketCmd _vecPacketCmds[] = {

	/**************  Common  *************/
	pck::EPacketCmd::KeepAlive,
	pck::EPacketCmd::LoginSrvRequest,
	pck::EPacketCmd::LoginSrvResult,
	/**************  Common  *************/


	/**************  Center  *************/
	pck::EPacketCmd::ServerListen,
	pck::EPacketCmd::ServerListenEx,
	/**************  Center  *************/


	pck::EPacketCmd::None
};

const int _nCmdCount = sizeof(_vecPacketCmds) / sizeof(int);	// packet cmd count