#include "stdafx.h"
#include "Include/db/TableDataSrv.h"
#include "Include/db/Log.h"

#include "json/json.h"
using namespace Json;


namespace db
{
	TableDataSrv::TableDataSrv() :
		DbService("Table", "Index")
	{

	}

	TableDataSrv::TableDataSrv(string addr) :
		DbService(addr)
	{

	}

	DbResult* TableDataSrv::ParseDbResult(HttpResponseData& data)
	{
		TableDataResult* pResult = new TableDataResult();

		Json::Value root;
		Json::Reader reader;
		reader.parse(data.bufContent, root);
		Json::Value bsData = root["data"];

		pResult->nId = bsData["Id"].asInt();
		pResult->strTableName = IsUTF8(data) ? UTF8_2_GB2312(bsData["Name"].asString()) : bsData["Name"].asString();
		pResult->nGameType = bsData["GameType"].asInt();
		pResult->nType = bsData["Type"].asInt();
		pResult->nStatus = bsData["Status"].asInt();
		pResult->nGroupCount = bsData["GroupCount"].asInt();
		pResult->nSeatCount = bsData["SeatCount"].asInt();
		pResult->nTypeId = bsData["TypeId"].asInt();

		pResult->bSuccess = true;

		return pResult;
	}
}