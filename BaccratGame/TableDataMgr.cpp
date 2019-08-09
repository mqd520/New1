#include "stdafx.h"
#include "TableDataMgr.h"
#include "GameService.h"


TableDataMgr::TableDataMgr(int nTableId) :
nTableId(nTableId)
{

}

void TableDataMgr::LoadTables()
{
	DbParameter param;
	param.Add("tableId", nTableId);

	dbSrv.ExecuteQuery(&param);
}

void TableDataMgr::OnLoadTablesCpl(DbService* pSrv, DbResult* pResult)
{
	TableDataResult* pResult1 = (TableDataResult*)pResult;
	tableData = pResult1->data;
}

void TableDataMgr::Init()
{
	dbSrv.SetDbCallback(std::bind(&TableDataMgr::OnLoadTablesCpl, this, _1, _2));
	LoadTables();
}

void TableDataMgr::Exit()
{
	dbSrv.Exit();
}

int TableDataMgr::GetTableId() const
{
	return nTableId;
}

void TableDataMgr::AttachGameService(GameService* pSrv)
{
	this->pGameSrv = pSrv;
}

TableData TableDataMgr::GetTableData() const
{
	TableData result = tableData;

	return result;
}