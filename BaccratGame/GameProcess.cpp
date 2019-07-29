#include "stdafx.h"
#include "GameProcess.h"
#include "GameService.h"

#include "com/StringTool.h"
using namespace com;


GameProcess::GameProcess(int nTableId) :
nTableId(nTableId),
nDuplicateId(1),
bNeedChangeXue(false)
{

}

void GameProcess::ApplyGameRound()
{
	DbParameter param;
	param.Add("TableId", nTableId);
	param.Add("DuplicateId", nDuplicateId);
	param.Add("IsNewXue", bNeedChangeXue);
	string dealerNo = pSrv->GetDealerMgr()->GetDealerNo();
	param.Add("DealerNo", StringTool::GB2312_2_UTF8((char*)dealerNo.c_str()));

	appGameRoundSrv.ExecuteQuery(&param);
}

void GameProcess::OnApplyGameRoundCpl(DbService* pSrv, DbResult* pResult)
{
	ApplyGameRoundResult* pResult1 = (ApplyGameRoundResult*)pResult;
	printf("Game round Id = %d \n", pResult1->nGameRoundId);
}

void GameProcess::Init()
{
	appGameRoundSrv.SetDbCallback(std::bind(&GameProcess::OnApplyGameRoundCpl, this, _1, _2));
}

void GameProcess::Exit()
{
	appGameRoundSrv.Exit();
}

void GameProcess::AttachGameService(GameService* pSrv)
{
	this->pSrv = pSrv;
}

int GameProcess::GetTableId()
{
	return nTableId;
}

void GameProcess::StartTable()
{
	ApplyGameRound();
}