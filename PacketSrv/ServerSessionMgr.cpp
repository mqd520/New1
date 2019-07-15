#include "stdafx.h"
#include "Include/pck/ServerSessionMgr.h"

namespace pck
{
	ServerSessionMgr::ServerSessionMgr()
	{

	}

	ServerSession* ServerSessionMgr::GetSession(int clientId)
	{
		ServerSession* p = NULL;

		for (vector<ServerSession*>::iterator it = vecSessions.begin(); it != vecSessions.end(); it++)
		{
			if ((*it)->GetClientId() == clientId)
			{
				p = *it;
				break;
			}
		}

		return p;
	}

	ServerSession* ServerSessionMgr::CreateSession(int clientId, void* pObj, bool recvPwd /*= true*/)
	{
		ServerSession* p = NULL;

		p = GetSession(clientId);
		if (p == NULL)
		{
			p = new ServerSession(clientId, pObj, recvPwd);
			vecSessions.push_back(p);
		}

		return p;
	}

	void ServerSessionMgr::CloseSession(int clientId)
	{
		for (vector<ServerSession*>::iterator it = vecSessions.begin(); it != vecSessions.end(); it++)
		{
			if ((*it)->GetClientId() == clientId)
			{
				(*it)->Close();
				delete *it;
				vecSessions.erase(it);

				break;
			}
		}
	}

	void ServerSessionMgr::CloseSession()
	{
		for (vector<ServerSession*>::iterator it = vecSessions.begin(); it != vecSessions.end(); it++)
		{
			(*it)->Close();
			delete *it;
			vecSessions.erase(it);
		}
	}
}