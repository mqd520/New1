#include "stdafx.h"
#include "TableDataMgr.h"
#include "GameService.h"
#include "Log.h"

#include "tc/TimerMoudleMgr.h"
using namespace tc;


#define ReloadTableDataTimeout		(10 * 1000)		// reload table data timeout


TableDataMgr::TableDataMgr(int nTableId) :
nTableId(nTableId),
pGameSrv(nullptr)
{
	ZeroMemory(&tableData, sizeof(TableData));
}

void TableDataMgr::LoadTable()
{
	Log::Printf(ELogType::Info, "Start load table data, Id: %d", nTableId);

	DbParameter param;
	param.Add("tableId", nTableId);

	dbSrv.ExecuteQuery(&param);
}

void TableDataMgr::OnDbCpl_LoadTable(DbService* pSrv, DbResult* pResult)
{
	t.Stop();

	TableDataResult* pResult1 = (TableDataResult*)pResult;
	if (pResult && pResult && pResult1->bSuccess)
	{
		tableData = pResult1->data;
		Log::Printf(ELogType::Info, "Load table data success, Id: %d, Name: %s", nTableId, tableData.strTableName.c_str());

		for (vector<LoadTableDataSuccessCallback>::iterator it = vecFns.begin(); it != vecFns.end(); it++)
		{
			if (!it->_Empty())
			{
				(*it)(this, pResult1->data);
			}
		}
	}
	else
	{
		Log::Printf(ELogType::Error, "Load table data fail, Id: %d", nTableId);
		
		t.Run();
	}
}

void TableDataMgr::OnTimer(Timer* pObj, int count, void* pParam1, void* pParam2)
{
	t.Stop();
	LoadTable();
}

void TableDataMgr::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

void TableDataMgr::Init()
{
	t.SetTimeout(ReloadTableDataTimeout);
	t.SetCallback(std::bind(&TableDataMgr::OnTimer, this, _1, _2, _3, _4));

	dbSrv.SetDbCallback(std::bind(&TableDataMgr::OnDbCpl_LoadTable, this, _1, _2));
	LoadTable();
}

void TableDataMgr::Exit()
{
	dbSrv.Exit();
	TimerMoudleMgr::GetTimerMgr()->Remove(&t);
}

int TableDataMgr::GetTableId() const
{
	return nTableId;
}

TableData TableDataMgr::GetTableData() const
{
	TableData result = tableData;

	return result;
}

void TableDataMgr::RegTableDataLoadSuccessEvt(LoadTableDataSuccessCallback fn)
{
	vecFns.push_back(fn);
}