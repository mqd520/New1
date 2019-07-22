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
	int nTableId;			// table Id
	TableDataSrv dbSrv;		// db srv

private:
	void LoadTableData();

	void OnDbSuccess(DbService* pSrv, DbResult* pResult);

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
};