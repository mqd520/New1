#include "stdafx.h"
#include "WebSocket.h"
#include "WebSocketServer.h"

#include "tc/TcpCommuMgr.h"
#include "tc/TcpServer.h"
#include "tc/Def.h"
#include "tc/Log.h"
using namespace tc;


void OnTcpLog(ETcpLogType type, string log, bool bOutput2Console);

WebSocketServer* pServer = NULL;


WebSocket::WebSocket()
{

}

void WebSocket::Init()
{
	TcpCommu::Init();
	TcpLog::SetCallbackFn(std::bind(OnTcpLog, _1, _2, _3));

	pServer = new WebSocketServer("127.0.0.1", 8021);
	bool b = pServer->Listen();
}

void OnTcpLog(ETcpLogType type, string log, bool bOutput2Console)
{
	printf("[%d] %s \n", (int)type, log.c_str());
}