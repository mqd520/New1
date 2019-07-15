#include "stdafx.h"
#include "ServerListenMgr.h"
#include "Def.h"
#include "CenterService.h"

#include "com/CommonTool.h"
using namespace com;

#include "tc/TimerMoudleMgr.h"
using namespace tc;


typedef vector<ServerListenInfo>::iterator	ITServerListen;


ServerListenMgr::ServerListenMgr()
{
	t.SetTimeout(CS_SendServerListen_Timespan);
	auto fun = std::bind(&ServerListenMgr::OnTimer, this, _1, _2, _3, _4);
	t.SetCallback(fun, NULL, NULL);
}

void ServerListenMgr::OnTimer(Timer* pTimer, int count, void* pParam1 /*= NULL*/, void* pParam2 /*= NULL*/)
{
	Send2AllServers();
}

void ServerListenMgr::Init()
{
	t.Run();
}

void ServerListenMgr::Exit()
{
	t.Stop();
	TimerMoudleMgr::GetTimerMgr()->Remove(&t);
}

void ServerListenMgr::Add(ServerListenPacket& pck, string peerIp, int peerPort)
{
	bool b = false;

	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->pck.ServerType == pck.ServerType && it->pck.nIP == pck.nIP && it->pck.nPort == pck.nPort)
		{
			b = true;
			break;
		}
	}

	if (!b)
	{
		vecPcks.push_back({ pck, peerIp, peerPort });
	}
}

void ServerListenMgr::Remove(ServerListenPacket& pck)
{
	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->pck.ServerType == pck.ServerType && it->pck.nIP == pck.nIP && it->pck.nPort == pck.nPort)
		{
			vecPcks.erase(it);
			break;
		}
	}
}

ServerListenPacket ServerListenMgr::Remove(string peerIp, int peerPort)
{
	ServerListenPacket pck;

	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->strPeerIp == peerIp && it->nPeerPort == peerPort)
		{
			pck = it->pck;
			vecPcks.erase(it);
			break;
		}
	}

	return pck;
}

void ServerListenMgr::Remove(EServerType type)
{
	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end();)
	{
		if (it->pck.ServerType == (int)type)
		{
			it = vecPcks.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void ServerListenMgr::Remove()
{
	vecPcks.clear();
}

ServerListenPacket ServerListenMgr::Get(string peerIp, int peerPort)
{
	ServerListenPacket pck;

	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->strPeerIp == peerIp && it->nPeerPort == peerPort)
		{
			pck = it->pck;
			break;
		}
	}

	return pck;
}

ServerListenPacket ServerListenMgr::Get(EServerType type, string peerIp, int peerPort)
{
	ServerListenPacket pck;

	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->pck.ServerType == (int)type && it->strPeerIp == peerIp && it->nPeerPort == peerPort)
		{
			pck = it->pck;
			break;
		}
	}

	return pck;
}

void ServerListenMgr::Get(vector<ServerListenPacket>& vec, EServerType type)
{
	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		if (it->pck.ServerType == (int)type)
		{
			vec.push_back(it->pck);
		}
	}
}

void ServerListenMgr::Get(vector<ServerListenPacket>& vec)
{
	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		vec.push_back(it->pck);
	}
}

void ServerListenMgr::Send2AllServers()
{
	for (ITServerListen it = vecPcks.begin(); it != vecPcks.end(); it++)
	{
		CenterService::GetInstance()->GetPlazaSrv()->SendPck2AllClients(it->pck);
	}
}