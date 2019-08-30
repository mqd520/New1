#include "stdafx.h"
#include "GameRoundService.h"
#include "GameService.h"
#include "Log.h"

#include "com/StringTool.h"
using namespace com;

#include "game/ApplyGameRoundCplEvt.h"
using namespace game;


GameRoundService::GameRoundService(int nTableId) :
nTableId(nTableId),
nGameRoundId(0),
strGameRoundNo(""),
nDuplicateId(1),
bNeedChangeXue(false),
nXue(1),
nPu(1),

bApplyNewGameRoundSuccessed(false),

pGameSrv(NULL)
{
	AttachObj(this);
}

void GameRoundService::LoadGameRoundData()
{
	// ...
}

void GameRoundService::OnDbCpl_ApplyGameRound(DbService* pSrv, DbResult* pResult)
{
	ApplyGameRoundResult* pResult1 = (ApplyGameRoundResult*)pResult;
	if (pResult1->nGameRoundId > 0)
	{
		nGameRoundId = pResult1->nGameRoundId;
		bNeedChangeXue = pResult1->bIsNewXue;
		strGameRoundNo = pResult1->strGameRoundNo;
		nXue = pResult1->nXue;
		nPu = pResult1->nPu;
		nDuplicateId = pResult1->nDuplicateId;
		bApplyNewGameRoundSuccessed = true;

		Log::Printf(ELogType::Info, "Apply new game round fail, tableId: %d, xue: %d, pu: %d, No: %s", nTableId, nXue, nPu, strGameRoundNo.c_str());

		for (vector<ApplyNewGameRoundSuccess>::iterator it = vecFns_ApplyNewGameRound.begin(); it != vecFns_ApplyNewGameRound.end(); it++)
		{
			if (!it->_Empty())
			{
				(*it)();
			}
		}
	}
	else
	{
		Log::Printf(ELogType::Error, "Apply new game round fail, tableId: %d", nTableId);
	}
}

void GameRoundService::OnGameStatusChanged(EGameStatus previous, EGameStatus current)
{
	if (previous == EGameStatus::Prepare && current == EGameStatus::Bet)
	{
		bApplyNewGameRoundSuccessed = false;
	}
}

void GameRoundService::Init()
{
	appGameRoundSrv.SetDbCallback(std::bind(&GameRoundService::OnDbCpl_ApplyGameRound, this, _1, _2));
	pGameSrv->GetGameStatusMgr()->RegStatusChanged(std::bind(&GameRoundService::OnGameStatusChanged, this, _1, _2));
}

void GameRoundService::Exit()
{
	appGameRoundSrv.Exit();
}

void GameRoundService::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

int GameRoundService::GetTableId() const
{
	return nTableId;
}

int GameRoundService::GetGameRoundId() const
{
	return nGameRoundId;
}

string GameRoundService::GetGameRoundNo() const
{
	return strGameRoundNo;
}

int GameRoundService::GetXue() const
{
	return nXue;
}

int GameRoundService::GetPu() const
{
	return nPu;
}

bool GameRoundService::IsApplyNewGameRoundSuccessed() const
{
	return bApplyNewGameRoundSuccessed;
}

void GameRoundService::ApplyNewRound()
{
	bApplyNewGameRoundSuccessed = false;

	Log::Printf(ELogType::Info, "Start apply new game round, tableId: %d", nTableId);

	DbParameter param;
	param.Add("TableId", nTableId);
	param.Add("DuplicateId", nDuplicateId);
	param.Add("IsNewXue", bNeedChangeXue);
	string dealerNo = pGameSrv->GetDealerMgr()->GetDealerNo();
	param.Add("DealerNo", StringTool::GB2312_2_UTF8((char*)dealerNo.c_str()));

	appGameRoundSrv.ExecuteQuery(&param);
}

void GameRoundService::SettleGameRound()
{

}

void GameRoundService::RegApplyNewGameRoundSuccess(ApplyNewGameRoundSuccess callback)
{
	vecFns_ApplyNewGameRound.push_back(callback);
}