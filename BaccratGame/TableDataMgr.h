#pragma once

#include <vector>
using namespace std;

#include "db/TableDataSrv.h"
using namespace db;


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
	//************************************
	// Method:    Load Table list
	//************************************
	void LoadTables();

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
	// Method:    Get table data
	//************************************
	TableData GetTableData() const;
};