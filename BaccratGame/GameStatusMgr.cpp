#include "stdafx.h"
#include "GameStatusMgr.h"

#include "GS_Stop.h"


GameStatusMgr::GameStatusMgr(int nTableId) :
nTableId(nTableId),
pCurGameStatus(NULL)
{

}

int GameStatusMgr::GetTableId()
{
	return nTableId;
}

void GameStatusMgr::Init()
{
	vecGS.push_back(new GS_Stop());

	pCurGameStatus = vecGS[0];
}

void GameStatusMgr::Exit()
{
	for (vector<GameStatus*>::iterator it = vecGS.begin(); it != vecGS.end(); it++)
	{
		(*it)->Exit();
		delete (*it);
	}

	vecGS.clear();
}

EGameMainStatus GameStatusMgr::GetCurGameMainStatus()
{
	return pCurGameStatus->GetCurGameMainStatus();
}

EGameStatus GameStatusMgr::GetCurGameStatus()
{
	return pCurGameStatus->GetCurGameStatus();
}