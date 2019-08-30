#include "stdafx.h"
#include "GameStatusMgr.h"
#include "GameService.h"

#include "GS_Stop.h"
#include "GS_Prepare.h"
#include "GS_Bet.h"
#include "GS_StopBet.h"
#include "GS_Send.h"
#include "GS_Publish.h"
#include "GS_Settle.h"

#include "db/TableData.h"
using namespace db;

#include "game/TableDef.h"
using namespace game;


GameStatusMgr::GameStatusMgr(int nTableId) :
nTableId(nTableId),
pCurGameStatus(nullptr),
pGameSrv(nullptr)
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

void GameStatusMgr::InitStatus(TableData& td)
{
	// td.dk_mode == (int)ENewGameRoundModel::Auto
	vecGS.push_back(new GS_Stop());
	vecGS.push_back(new GS_Prepare(false, td.dk_dtprepare));
	vecGS.push_back(new GS_Bet(true, td.dk_dtstartbet));
	vecGS.push_back(new GS_StopBet(true, td.dk_dtstartbet));
	vecGS.push_back(new GS_Send(false, td.dk_dtdeal));
	vecGS.push_back(new GS_Publish(false, td.dk_dtshow));
	vecGS.push_back(new GS_Settle(false, td.dk_dtAmount));

	vecGS[1]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// prepare	status
	vecGS[2]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// bet		status
	vecGS[3]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// stop bet	status
	vecGS[4]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// send		status
	vecGS[5]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// publish	status
	vecGS[6]->RegCountdownCpl(std::bind(&GameStatusMgr::OnCountDownCpl, this, _1, _2));		// settle	status

	pCurGameStatus = vecGS[0];	// default status: stop

	for (vector<GameStatusInitedCallback>::iterator it = vecFn1s.begin(); it != vecFn1s.end(); it++)
	{
		(*it)();
	}

	pCurGameStatus->Enter();
}

void GameStatusMgr::OnStatusChanged(EGameStatus previous, EGameStatus current)
{
	for (vector<GameStatusChangedCallback>::iterator it = vecFns.begin(); it != vecFns.end(); it++)
	{
		if (!it->_Empty())
		{
			(*it)(previous, current);
		}
	}
}

void GameStatusMgr::OnLoadTableDataSuccess(TableDataMgr* ptd, TableData& td)
{
	InitStatus(td);
}

void GameStatusMgr::OnCountDownCpl(GameStatus* p, int nTime)
{
	for (vector<CountDownCplCallback1>::iterator it = vecFn2s.begin(); it != vecFn2s.end(); it++)
	{
		if (it->_Empty())
		{
			(*it)(p->GetCurGameStatus(), nTime);
		}
	}
}

void GameStatusMgr::AttachGameService(GameService* pSrv)
{
	pGameSrv = pSrv;
}

void GameStatusMgr::Init()
{
	pGameSrv->GetTableDataMgr()->RegTableDataLoadSuccessEvt(std::bind(&GameStatusMgr::OnLoadTableDataSuccess, this, _1, _2));
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

GameStatus* GameStatusMgr::GetGameStatusObj(EGameStatus status)
{
	GameStatus* p = nullptr;

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

GameStatus* GameStatusMgr::GetCurGameStatusObj()
{
	return pCurGameStatus;
}

bool GameStatusMgr::ChangeStatus(EGameStatus status, bool bForce /*= false*/, bool bEvt /*= true*/)
{
	bool result = false;

	bool bChange = bForce ? true : pCurGameStatus && pCurGameStatus->IsReady();		// whether change status
	if (bChange)
	{
		EGameStatus previous = pCurGameStatus->GetCurGameStatus();
		if (status != previous)
		{
			GameStatus* p = GetGameStatus(status);
			if (p)
			{
				pCurGameStatus->Leave();
				pCurGameStatus = p;
				pCurGameStatus->Enter();
				if (bEvt)
				{
					OnStatusChanged(previous, status);
				}

				result = true;
			}
		}
	}

	return result;
}

bool GameStatusMgr::EnterNextStatus(bool bForce /*= false*/, bool bEvt /*= true*/)
{
	return ChangeStatus(pCurGameStatus->GetNextStatus(), bForce, bEvt);
}

void GameStatusMgr::RegStatusChanged(GameStatusChangedCallback callback)
{
	vecFns.push_back(callback);
}

void GameStatusMgr::RegStatusInited(GameStatusInitedCallback callback)
{
	vecFn1s.push_back(callback);
}

void GameStatusMgr::RegCountDownCpl(CountDownCplCallback1 callback)
{
	vecFn2s.push_back(callback);
}