#include "stdafx.h"
#include "GameRoundService.h"
#include "GameService.h"
#include "Log.h"

#include "com/StringTool.h"
using namespace com;

#include "game/ApplyGameRoundCplEvt.h"
using namespace game;


GameRoundService::GameRoundService(int nTableId) :
//GameEvtReg(),

nTableId(nTableId),
nGameRoundId(0),
strGameRoundNo(""),
nDuplicateId(1),
bNeedChangeXue(false),
nXue(1),
nPu(1),

pGameSrv(NULL)
{
	AttachObj(this);
}

void GameRoundService::LoadGameRoundData()
{
	// ...
}

void GameRoundService::OnApplyGameRoundCpl(DbService* pSrv, DbResult* pResult)
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
	}
	else
	{
		WriteLog(ELogType::Error, true, "Apply new game round fail, tableId: %d, xue: %d, pu: %d", nTableId, nXue, nPu);
	}

	TriggerEvt(EGameEvtType::ApplyGameRoundCpl, ApplyGameRoundCplEvt(pResult1->nGameRoundId > 0));
}

void GameRoundService::Init()
{
	appGameRoundSrv.SetDbCallback(std::bind(&GameRoundService::OnApplyGameRoundCpl, this, _1, _2));
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

void GameRoundService::ApplyNewRound()
{
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