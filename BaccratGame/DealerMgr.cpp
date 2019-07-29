#include "stdafx.h"
#include "DealerMgr.h"

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

int DealerMgr::GetTableId()
{
	return nTableId;
}

bool DealerMgr::hasDealer()
{
	return !strDealerNo.empty();
}

string DealerMgr::GetDealerNo()
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