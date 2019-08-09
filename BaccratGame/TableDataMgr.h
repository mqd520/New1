#pragma once

#include <vector>
using namespace std;

#include "db/TableDataSrv.h"
using namespace db;

class GameService;


// Table data mgr
class TableDataMgr
{
public:
	TableDataMgr(int nTableId);

private:
	int nTableId;				// table Id
	TableDataSrv dbSrv;			// db srv
	TableData tableData;		// table data

private:
	GameService* pGameSrv;		// game service obj

private:
	//************************************
	// Method:    Load Table list
	//************************************
	void LoadTables();

private:
	//************************************
	// Method:    Load tables complete
	// Parameter: DbService * pSrv
	// Parameter: DbResult * pResult
	//************************************
	void OnLoadTablesCpl(DbService* pSrv, DbResult* pResult);

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
	// Method:    Attach game service
	// Parameter: GameService * pSrv
	//************************************
	void AttachGameService(GameService* pSrv);

	//************************************
	// Method:    Get table data
	//************************************
	TableData GetTableData() const;
};