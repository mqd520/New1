#pragma once

#include <vector>
using namespace std;

#include "tc/Timer.h"
using namespace tc;

#include "db/TableDataSrv.h"
using namespace db;

#include "game/GameEvtReg.h"
using namespace game;


class GameService;
class TableDataMgr;


// TableDataMgr *
// TableData &
using LoadTableDataSuccessCallback = std::function < void(TableDataMgr*, TableData&) >;


// Table data mgr
class TableDataMgr : public GameEvtReg
{
public:
	//************************************
	// Method:    Constructor
	// Parameter: int nTableId
	//************************************
	TableDataMgr(int nTableId);

private:
	int nTableId;				// table Id
	TableDataSrv dbSrv;			// db srv
	TableData tableData;		// table data
	vector<LoadTableDataSuccessCallback> vecFns;	// load table data success callback
	Timer t;					// load table timer

private:
	GameService* pGameSrv;		// game service obj

private:
	//************************************
	// Method:    Load Table Data
	//************************************
	void LoadTable();

private:
	//************************************
	// Method:    Load table complete
	// Parameter: DbService * pSrv
	// Parameter: DbResult * pResult
	//************************************
	void OnDbCpl_LoadTable(DbService* pSrv, DbResult* pResult);

	//************************************
	// Method:    OnTimer
	// Parameter: Timer * pObj
	// Parameter: int count
	// Parameter: void * pParam1
	// Parameter: void * pParam1
	//************************************
	void OnTimer(Timer* pObj, int count, void* pParam1, void* pParam2);

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
	// Method:    Get table data
	//************************************
	TableData GetTableData() const;

	//************************************
	// Method:    Reg load table data success evt
	// Parameter: LoadTableDataSuccessCallback fn
	//************************************
	void RegTableDataLoadSuccessEvt(LoadTableDataSuccessCallback fn);
};