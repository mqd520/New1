#pragma once

#include <vector>
using namespace std;

#include "def/GameDef.h"
using namespace gameDef;


// Game round data service
class GameRoundService
{
public:
	GameRoundService(int nTableId);

private:
	int nTableId;				// table Id
	int nGameRoundId;			// round id
	string strGameRoundNo;		// round no
	vector<int> vecResults;		// game round result list

private:
	//************************************
	// Method:    Load history data
	//************************************
	void LoadGameRoundData();

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
	// Method:    Get table Id
	//************************************
	int GetTableId();

	int GetGameRoundId();

	string GetGameRoundNo();

	void CreateNewRound();

	void SettleGameRound();
};