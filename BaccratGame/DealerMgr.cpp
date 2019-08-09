#include "stdafx.h"
#include "DealerMgr.h"
#include "GameService.h"


DealerMgr::DealerMgr(int nTableId) :
nTableId(nTableId)
{

}

void DealerMgr::Init()
{

}

void DealerMgr::Exit()
{

}

int DealerMgr::GetTableId() const
{
	return nTableId;
}

void DealerMgr::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

bool DealerMgr::hasDealer() const
{
	return !strDealerNo.empty();
}

string DealerMgr::GetDealerNo() const
{
	return strDealerNo;
}

void DealerMgr::DealerEnterGame(string strDealerNo)
{
	this->strDealerNo = strDealerNo;
}

void DealerMgr::DealerLeaveGame()
{

}