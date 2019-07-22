#include "stdafx.h"
#include "TableDataMgr.h"

TableDataMgr::TableDataMgr(int nTableId) :
nTableId(nTableId)
{

}

void TableDataMgr::LoadTableData()
{
	DbParameter param;
	param.Add("tableId", nTableId);
	dbSrv.ExecuteQuery(&param);
}

void TableDataMgr::OnDbSuccess(DbService* pSrv, DbResult* pResult)
{
	TableDataResult* pResult1 = (TableDataResult*)pResult;
}

void TableDataMgr::Init()
{
	dbSrv.SetDbCallback(std::bind(&TableDataMgr::OnDbSuccess, this, _1, _2));
	LoadTableData();
}

void TableDataMgr::Exit()
{
	dbSrv.Exit();
}

int TableDataMgr::GetTableId()
{
	return nTableId;
}