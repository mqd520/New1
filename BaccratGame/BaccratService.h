#pragma once

#include "GameCenterService.h"
#include "GameServiceMgr.h"

// Table Service
class BaccratService final
{
private:
	BaccratService();

public:
	//************************************
	// Method:    Get the origin BaccratService instance
	//************************************
	static BaccratService* GetInstance();

private:
	GameCenterService gameCenterSrv;	// Game center service obj
	GameServiceMgr	gameSrvMgr;			// GameService Mgr obj

public:
	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();

	//************************************
	// Method:    Get game center service obj
	//************************************
	GameCenterService* GetGameCenterSrv();

	//************************************
	// Method:    Get GameService mgr obj
	//************************************
	GameServiceMgr* GetGameSrvMgr();
};