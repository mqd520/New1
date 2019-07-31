#include "stdafx.h"
#include "Include/db/TableDataSrv2.h"
#include "Include/db/Log.h"

#include "json/json.h"
using namespace Json;


namespace db
{
	TableDataSrv2::TableDataSrv2() :
		DbService("Table", "LoadAll")
	{

	}

	TableDataSrv2::TableDataSrv2(string addr) :
		DbService(addr)
	{

	}

	DbResult* TableDataSrv2::ParseDbResult(HttpResponseData& data)
	{
		TableDataResult2* pResult = new TableDataResult2();

		Json::Value root;
		Json::Reader reader;
		reader.parse(data.bufContent, root);
		Json::Value bsData = root["data"];

		bool bUTF8 = IsUTF8(data);

		int n1 = bsData["TableDatas"].size();
		for (int i = 0; i < n1; i++)
		{
			Json::Value item = bsData["TableDatas"][i];

			TableData tData;
			tData.nId = item["Id"].asInt();
			tData.strTableName = bUTF8 ? UTF8_2_GB2312(item["Name"].asString()) : item["Name"].asString();
			tData.dk_passport = bUTF8 ? UTF8_2_GB2312(item["Passport"].asString()) : item["Passport"].asString();
			tData.dk_password = bUTF8 ? UTF8_2_GB2312(item["Password"].asString()) : item["Password"].asString();
			tData.dk_dtAmount = item["DTAmount"].asInt();
			tData.DealerNo = bUTF8 ? UTF8_2_GB2312(item["DealerNo"].asString()) : item["DealerNo"].asString();
			tData.VisitPwd = bUTF8 ? UTF8_2_GB2312(item["VisitPwd"].asString()) : item["VisitPwd"].asString();
			tData.nGameType = item["GameType"].asInt();
			tData.nTypeId = item["TypeId"].asInt();
			tData.dk_mcid10000 = item["dk_mcid10000"].asInt();
			tData.dk_seatMin = item["dk_seatMin"].asInt();
			tData.dk_dtDelayBet = item["dk_dtDelayBet"].asInt();
			tData.dk_publishresult = item["dk_publishresult"].asInt();
			tData.dk_mode = item["dk_mode"].asInt();
			tData.dk_dtprepare = item["dk_dtprepare"].asInt();
			tData.dk_dtstartbet = item["dk_dtstartbet"].asInt();
			tData.dk_dtstopbet = item["dk_dtstopbet"].asInt();
			tData.dk_dtdeal = item["dk_dtdeal"].asInt();
			tData.dk_dtshow = item["dk_dtshow"].asInt();
			tData.dk_dtwait = item["dk_dtwait"].asInt();
			tData.dk_mbettime = item["dk_mbettime"].asInt();
			tData.dk_dtMiPower = item["dk_dtMiPower"].asInt();
			tData.dk_dtMiTime1 = item["dk_dtMiTime1"].asInt();
			tData.dk_dtMiTime2 = item["dk_dtMiTime2"].asInt();
			tData.Type1 = item["Type1"].asInt();
			tData.Type2 = item["Type2"].asInt();
			tData.Type3 = item["Type3"].asInt();
			tData.nGroupCount = item["GroupCount"].asInt();
			tData.nSeatCount = item["SeatCount"].asInt();
			tData.dk_accprofit_first = item["dk_accprofit_first"].asInt();
			tData.dk_videotype = item["dk_videotype"].asInt();
			tData.dk_mcid10060 = item["dk_mcid10060"].asInt();

			pResult->vecTables.push_back(tData);
		}

		int n2 = bsData["UpdatedTableIds"].size();
		for (int j = 0; j < n2; j++)
		{
			Json::Value item = bsData["UpdatedTableIds"][j];

			pResult->vecUpdatedTableIds.push_back(item.asInt());
		}

		pResult->bSuccess = true;

		return pResult;
	}
}