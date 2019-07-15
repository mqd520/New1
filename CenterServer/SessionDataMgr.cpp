#include "stdafx.h"
#include "SessionDataMgr.h"

typedef vector<SessionData>::iterator	ITSessionData;

SessionDataMgr::SessionDataMgr()
{

}

SessionDataMgr::~SessionDataMgr()
{

}

void SessionDataMgr::Add(SessionData& data)
{
	bool b = false;
	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->peerType == data.peerType && data.strClientIp == data.strClientIp && data.nClientPort == data.nClientPort)
		{
			b = true;
			break;
		}
	}

	if (!b)
	{
		vecDatas.push_back(data);
	}
}

void SessionDataMgr::Remove(EServerType peerType)
{
	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end();)
	{
		if (it->peerType == peerType)
		{
			it = vecDatas.erase(it);
		}
		else
		{
			it++;
		}
	}
}

SessionData SessionDataMgr::Remove(int clientId)
{
	SessionData data = { 0 };

	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->nClientId == clientId)
		{
			data = *it;
			vecDatas.erase(it);
			break;
		}
	}

	return data;
}

SessionData SessionDataMgr::Remove(string ip, int port)
{
	SessionData data = { 0 };

	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->strClientIp == ip && it->nClientPort == port)
		{
			data = *it;
			vecDatas.erase(it);
			break;
		}
	}

	return data;
}

void SessionDataMgr::Remove(SessionData& data)
{
	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->nClientId == data.nClientId && it->nClientPort == data.nClientPort &&
			it->peerType == data.peerType && it->pParam1 == data.pParam1 &&
			it->pParam2 == data.pParam2 && it->strClientIp == data.strClientIp)
		{
			vecDatas.erase(it);
			break;
		}
	}
}

void SessionDataMgr::Remove()
{
	vecDatas.clear();
}

void SessionDataMgr::Get(vector<SessionData>& vec, EServerType peerType)
{
	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->peerType == peerType)
		{
			vec.push_back(*it);
		}
	}
}

SessionData SessionDataMgr::Get(int clientId)
{
	SessionData data = { 0 };

	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->nClientId == clientId)
		{
			data = *it;
			break;
		}
	}

	return data;
}

SessionData SessionDataMgr::Get(string ip, int port)
{
	SessionData data = { 0 };

	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		if (it->strClientIp == ip && it->nClientPort == port)
		{
			data = *it;
			break;
		}
	}

	return data;
}

void SessionDataMgr::Get(vector<SessionData>& vec)
{
	for (ITSessionData it = vecDatas.begin(); it != vecDatas.end(); it++)
	{
		vec.push_back(*it);
	}
}