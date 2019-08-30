#include "stdafx.h"
#include "GameProcess.h"
#include "GameService.h"
#include "Log.h"

#include "game/ApplyGameRoundCplEvt.h"
using namespace game;


GameProcess::GameProcess(int nTableId) :
nTableId(nTableId),
pGameSrv(nullptr)
{

}

void GameProcess::OnApplyGameRoundSuccess()
{
	pGameSrv->GetGameStatusMgr()->GetCurGameStatusObj()->SetReadyState();
}

void GameProcess::OnGameStatusInited()
{

}

void GameProcess::OnGameStatusChanged(EGameStatus previous, EGameStatus current)
{
	// send table status changed pck
	pGameSrv->SendPck_2_GameCenter();

	Log::Printf(ELogType::Debug, "Table status changed, from %d to %d", (int)previous, (int)current);
}

void GameProcess::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

void GameProcess::Init()
{
	pGameSrv->GetGameRoundSrv()->RegApplyNewGameRoundSuccess(std::bind(&GameProcess::OnApplyGameRoundSuccess, this));
	pGameSrv->GetGameStatusMgr()->RegStatusInited(std::bind(&GameProcess::OnGameStatusInited, this));
}

void GameProcess::Exit()
{

}

int GameProcess::GetTableId() const
{
	return nTableId;
}

void GameProcess::StartTable()
{
	if (pGameSrv->GetGameStatusMgr()->GetCurGameStatus() == EGameStatus::Stop)
	{
		pGameSrv->GetGameStatusMgr()->ChangeStatus(EGameStatus::Prepare, true);
		pGameSrv->GetGameRoundSrv()->ApplyNewRound();

		Log::Printf(ELogType::Info, "Start table success, table: %s", pGameSrv->GetTableDataMgr()->GetTableData().strTableName.c_str());
	}
}

void GameProcess::StartBet()
{
	bool b = false;
	char chMsg[100] = { 0 };

	pGameSrv->GetGameStatusMgr()->GetCurGameStatusObj()->SetReadyState();

	if (pGameSrv->GetGameStatusMgr()->GetCurGameStatus() == EGameStatus::Prepare)
	{
		b = pGameSrv->GetGameStatusMgr()->EnterNextStatus();
		if (b)
		{

		}
		else
		{
			sprintf_s(chMsg, "not ready");
		}
	}
	else
	{
		sprintf_s(chMsg, "not int \"prepare\" status, cur status: %d", (int)pGameSrv->GetGameStatusMgr()->GetCurGameStatus());
	}

	Log::Printf(b ? ELogType::Info : ELogType::Error, "Enter bet status %s, table: %s, msg: %s",
		b ? "success" : "fail", pGameSrv->GetTableDataMgr()->GetTableData().strTableName.c_str(), chMsg);
}

void GameProcess::StopBet()
{
	if (pGameSrv->GetGameStatusMgr()->GetCurGameStatus() == EGameStatus::Bet)
	{
		pGameSrv->GetGameStatusMgr()->EnterNextStatus();

		Log::Printf(ELogType::Debug, "Enter stop bet status");
	}
}