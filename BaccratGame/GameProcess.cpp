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

void GameProcess::OnApplyGameRoundCpl(GameEvt* pEvt, void* pObj)
{
	ApplyGameRoundCplEvt* pEvt1 = (ApplyGameRoundCplEvt*)pEvt;
	if (pEvt1->IsSuccessed())
	{
		pGameSrv->GetGameStatusMgr()->EnterNextStatus();
	}
}

void GameProcess::Init()
{
	pGameSrv->GetGameRoundSrv()->RegGameEvt(EGameEvtType::ApplyGameRoundCpl,
		std::bind(&GameProcess::OnApplyGameRoundCpl, this, _1, _2));
}

void GameProcess::Exit()
{

}

void GameProcess::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

int GameProcess::GetTableId() const
{
	return nTableId;
}

void GameProcess::StartTable()
{
	pGameSrv->GetGameRoundSrv()->ApplyNewRound();
	pGameSrv->GetGameStatusMgr()->ChangeStatus(EGameStatus::Prepare);
}