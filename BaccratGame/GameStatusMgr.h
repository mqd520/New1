#pragma once

#include <vector>
using namespace std;

#include "GameStatus.h"


// GameStatusMgr
class GameStatusMgr
{
public:
	GameStatusMgr(int nTableId);

private:
	int nTableId;					// table Id
	vector<GameStatus*> vecGS;		// game status obj list
	GameStatus* pCurGameStatus;		// current game status obj

public:
	int GetTableId();

	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();

	EGameMainStatus GetCurGameMainStatus();

	EGameStatus GetCurGameStatus();
};