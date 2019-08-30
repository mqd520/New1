#pragma once

#include <vector>
using namespace std;

#include "GameStatus.h"
#include "TableDataMgr.h"


class GameService;


// Game status changed evt callback
// EGameStatus:	old game status
// EGameStatus:	current game status
using GameStatusChangedCallback = std::function < void(EGameStatus, EGameStatus) > ;

// Game status inited evt callback
using GameStatusInitedCallback = std::function < void(void) > ;

// CountDown complete evt callback
// EGameStatus:	EGameStatus
// int:			countdown duration time
using CountDownCplCallback1 = std::function < void(EGameStatus, int) > ;


// GameStatusMgr
class GameStatusMgr
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: int nTableId
	//************************************
	GameStatusMgr(int nTableId);

private:
	int nTableId;					// table Id
	vector<GameStatus*> vecGS;		// game status obj list
	GameStatus* pCurGameStatus;		// current game status obj

private:
	GameService* pGameSrv;			// game service obj

private:
	vector<GameStatusChangedCallback> vecFns;	// callback list: game status changed
	vector<GameStatusInitedCallback> vecFn1s;	// callback list: game status inited
	vector<CountDownCplCallback1> vecFn2s;		// callback list: countdown complete

private:
	//************************************
	// Method:    Get GameStatus obj
	//************************************
	GameStatus* GetGameStatus(EGameStatus status);

	//************************************
	// Method:    Init status
	// Parameter: TableData & td
	//************************************
	void InitStatus(TableData& td);

private:
	//************************************
	// Method:    Game status changed evt handle
	// Parameter: EGameStatus previous
	// Parameter: EGameStatus current
	//************************************
	void OnStatusChanged(EGameStatus previous, EGameStatus current);

	//************************************
	// Method:    Load table data success evt handler
	// Parameter: TableDataMgr * ptd
	// Parameter: TableData & td
	//************************************
	void OnLoadTableDataSuccess(TableDataMgr* ptd, TableData& td);

	//************************************
	// Method:    Countdown complete evt handle
	// Parameter: GameStatus * p
	// Parameter: int nTime
	//************************************
	void OnCountDownCpl(GameStatus* p, int nTime);

public:
	//************************************
	// Method:    Attach game service
	// Parameter: GameService * pSrv
	//************************************
	void AttachGameService(GameService* pSrv);

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
	// Method:    Get game status obj
	// Parameter: status: EGameStatus
	//************************************
	GameStatus* GetGameStatusObj(EGameStatus status);

	//************************************
	// Method:    Get current game status obj
	//************************************
	GameStatus* GetCurGameStatusObj();

	//************************************
	// Method:    Change game status
	// Parameter: status: EGameStatus
	// Parameter: bForce: whether force change status
	// Parameter: bEvt:	  whether build evt
	//************************************
	bool ChangeStatus(EGameStatus status, bool bForce = false, bool bEvt = true);

	//************************************
	// Method:    Enter next status
	// Parameter: bForce: whether force enter next status
	// Parameter: bEvt:	  whether build evt
	//************************************
	bool EnterNextStatus(bool bForce = false, bool bEvt = true);

	//************************************
	// Method:    Reg game status changed evt
	// Parameter: GameStatusChangedCallback callback
	//************************************
	void RegStatusChanged(GameStatusChangedCallback callback);

	//************************************
	// Method:    Reg game status inited evt
	// Parameter: GameStatusInitedCallback callback
	//************************************
	void RegStatusInited(GameStatusInitedCallback callback);

	//************************************
	// Method:    Reg CountDown Complete evt
	// Parameter: CountDownCplCallback1 callback
	//************************************
	void RegCountDownCpl(CountDownCplCallback1 callback);
};