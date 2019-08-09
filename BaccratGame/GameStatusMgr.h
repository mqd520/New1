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

private:
	void OnStatusChange(EGameStatus oldStatus, EGameStatus newStatus);

	GameStatus* GetGameStatus(EGameStatus status);

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
	int GetTableId() const;

	//************************************
	// Method:    Get current game main status
	//************************************
	EGameMainStatus GetCurGameMainStatus() const;

	//************************************
	// Method:    Get current game status
	//************************************
	EGameStatus GetCurGameStatus() const;

	//************************************
	// Method:    Change game status
	// Parameter: bForce: whether force change status
	// Parameter: bEvt:	  whether build evt
	//************************************
	void ChangeStatus(EGameStatus status, bool bForce = false, bool bEvt = true);

	//************************************
	// Method:    Enter next status
	// Parameter: bForce: whether force enter next status
	// Parameter: bEvt:	  whether build evt
	//************************************
	void EnterNextStatus(bool bForce = false, bool bEvt = true);
};