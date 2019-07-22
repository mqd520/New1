#include "stdafx.h"
#include "Include/db/TableDataSrv.h"
#include "Include/db/Log.h"

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

		int code = root["code"].asInt();
		pResult->bSuccess = code == 0;
		if (pResult->bSuccess)
		{
			Json::Value bsData = root["data"];

			pResult->nId = bsData["Id"].asInt();
			pResult->strTableName = IsUTF8(data) ? UTF8_2_GB2312(bsData["Name"].asString()) : bsData["Name"].asString();
			pResult->nGameType = bsData["GameType"].asInt();
			pResult->nType = bsData["Type"].asInt();
			pResult->nStatus = bsData["Status"].asInt();
			pResult->nGroupCount = bsData["GroupCount"].asInt();
			pResult->nSeatCount = bsData["SeatCount"].asInt();
			pResult->nTypeId = bsData["TypeId"].asInt();
		}
		else
		{
			DbLog::WriteLine(EDbLogType::Error, true, "parse table data result error, code: %d, json: %s", code, data.bufContent.c_str());
		}

		return pResult;
	}
}