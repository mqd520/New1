#include "stdafx.h"
#include "GameStatusMgr.h"

#include "GS_Stop.h"
#include "GS_Prepare.h"


GameStatusMgr::GameStatusMgr(int nTableId) :
nTableId(nTableId),
pCurGameStatus(nullptr)
{

}

GameStatus* GameStatusMgr::GetGameStatus(EGameStatus status)
{
	GameStatus* p = NULL;

	for (vector<GameStatus*>::iterator it = vecGS.begin(); it != vecGS.end(); it++)
	{
		if ((*it)->GetCurGameStatus() == status)
		{
			p = *it;
			break;
		}
	}

	return p;
}

void GameStatusMgr::OnStatusChange(EGameStatus oldStatus, EGameStatus newStatus)
{
	// ... trigger change evt
}

void GameStatusMgr::Init()
{
	vecGS.push_back(new GS_Stop());
	vecGS.push_back(new GS_Prepare());

	pCurGameStatus = vecGS[0];	// default status: stop
	pCurGameStatus->Enter();
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

int GameStatusMgr::GetTableId() const
{
	return nTableId;
}

EGameMainStatus GameStatusMgr::GetCurGameMainStatus() const
{
	return pCurGameStatus->GetCurGameMainStatus();
}

EGameStatus GameStatusMgr::GetCurGameStatus() const
{
	return pCurGameStatus->GetCurGameStatus();
}

void GameStatusMgr::ChangeStatus(EGameStatus status, bool bForce /*= false*/, bool bEvt /*= true*/)
{
	bool bChange = bForce ? true : pCurGameStatus && pCurGameStatus->IsCompleted();		// whether change status
	if (bChange)
	{
		EGameStatus oldStatus = pCurGameStatus->GetCurGameStatus();
		if (status != oldStatus)
		{
			GameStatus* p = GetGameStatus(status);
			if (p)
			{
				pCurGameStatus->Leave();
				pCurGameStatus = p;
				pCurGameStatus->Enter();
				if (bEvt)
				{
					OnStatusChange(oldStatus, status);
				}
			}
		}
	}
}

void GameStatusMgr::EnterNextStatus(bool bForce /*= false*/, bool bEvt /*= true*/)
{
	ChangeStatus(pCurGameStatus->GetNextStatus(), bForce, bEvt);
}