#include "stdafx.h"
#include "Session1Mgr.h"

Session1Mgr::Session1Mgr()
{

}

Session1Mgr::~Session1Mgr()
{

}

SessionDataMgr* Session1Mgr::GetSessionDataMgr()
{
	return &sdMgr;
}