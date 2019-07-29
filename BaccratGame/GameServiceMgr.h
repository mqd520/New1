#pragma once

#include <vector>
using namespace std;

#include "GameService.h"


// Game service mgr
class GameServiceMgr
{
public:
	GameServiceMgr();
	~GameServiceMgr();

private:
	vector<GameService*> vecGameSrvs;	// GameService list

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
	// Method:    Get GameService obj
	//************************************
	GameService* GetGameSrv(int nTableId);

	void CreateGameService(vector<int>& vecTableIds);
};