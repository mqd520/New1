#include "stdafx.h"
#include "GameServiceMgr.h"

GameServiceMgr::GameServiceMgr()
{

}

GameServiceMgr::~GameServiceMgr()
{

}

void GameServiceMgr::Init()
{

}

void GameServiceMgr::Exit()
{
	for (vector<GameService*>::iterator it = vecGameSrvs.begin(); it != vecGameSrvs.end(); it++)
	{
		(*it)->Exit();
		delete *it;
	}

	vecGameSrvs.clear();
}

GameService* GameServiceMgr::GetGameSrv(int nTableId)
{
	GameService* p = NULL;

	for (vector<GameService*>::iterator it = vecGameSrvs.begin(); it != vecGameSrvs.end(); it++)
	{
		if ((*it)->GetTableId() == nTableId)
		{
			p = *it;
			break;
		}
	}

	return p;
}

void GameServiceMgr::CreateGameService(vector<int>& vecTableIds)
{
	for (vector<int>::iterator it = vecTableIds.begin(); it != vecTableIds.end(); it++)
	{
		bool b = false;

		for (vector<GameService*>::iterator it1 = vecGameSrvs.begin(); it1 != vecGameSrvs.end(); it1++)
		{
			if (*it == (*it1)->GetTableId())
			{
				b = true;
				break;
			}
		}

		if (!b)
		{
			GameService* p = new GameService(*it);
			p->Init();
			vecGameSrvs.push_back(p);
		}
	}
}