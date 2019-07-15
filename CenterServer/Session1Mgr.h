#pragma once

#include "SessionDataMgr.h"


// session mgr
class Session1Mgr
{
public:
	Session1Mgr();
	virtual ~Session1Mgr();

protected:
	SessionDataMgr sdMgr;	//	session data mgr

public:
	SessionDataMgr* GetSessionDataMgr();
};