#include "stdafx.h"
#include "Include/db/TableDataSrv.h"
#include "Include/db/Log.h"

#include "json/json.h"
using namespace Json;


namespace db
{
	TableDataSrv::TableDataSrv() :
		DbService("Table", "LoadById")
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

		bool bUTF8 = IsUTF8(data);

		TableData tData;
		tData.nId = bsData["Id"].asInt();
		tData.strTableName = bUTF8 ? UTF8_2_GB2312(bsData["Name"].asString()) : bsData["Name"].asString();
		tData.dk_passport = bUTF8 ? UTF8_2_GB2312(bsData["Passport"].asString()) : bsData["Passport"].asString();
		tData.dk_password = bUTF8 ? UTF8_2_GB2312(bsData["Password"].asString()) : bsData["Password"].asString();
		tData.dk_dtAmount = bsData["DTAmount"].asInt();
		tData.DealerNo = bUTF8 ? UTF8_2_GB2312(bsData["DealerNo"].asString()) : bsData["DealerNo"].asString();
		tData.VisitPwd = bUTF8 ? UTF8_2_GB2312(bsData["VisitPwd"].asString()) : bsData["VisitPwd"].asString();
		tData.nGameType = bsData["GameType"].asInt();
		tData.nTypeId = bsData["TypeId"].asInt();
		tData.dk_mcid10000 = bsData["dk_mcid10000"].asInt();
		tData.dk_seatMin = bsData["dk_seatMin"].asInt();
		tData.dk_dtDelayBet = bsData["dk_dtDelayBet"].asInt();
		tData.dk_publishresult = bsData["dk_publishresult"].asInt();
		tData.dk_mode = bsData["dk_mode"].asInt();
		tData.dk_dtprepare = bsData["dk_dtprepare"].asInt();
		tData.dk_dtstartbet = bsData["dk_dtstartbet"].asInt();
		tData.dk_dtstopbet = bsData["dk_dtstopbet"].asInt();
		tData.dk_dtdeal = bsData["dk_dtdeal"].asInt();
		tData.dk_dtshow = bsData["dk_dtshow"].asInt();
		tData.dk_dtwait = bsData["dk_dtwait"].asInt();
		tData.dk_mbettime = bsData["dk_mbettime"].asInt();
		tData.dk_dtMiPower = bsData["dk_dtMiPower"].asInt();
		tData.dk_dtMiTime1 = bsData["dk_dtMiTime1"].asInt();
		tData.dk_dtMiTime2 = bsData["dk_dtMiTime2"].asInt();
		tData.Type1 = bsData["Type1"].asInt();
		tData.Type2 = bsData["Type2"].asInt();
		tData.Type3 = bsData["Type3"].asInt();
		tData.nGroupCount = bsData["GroupCount"].asInt();
		tData.nSeatCount = bsData["SeatCount"].asInt();
		tData.dk_accprofit_first = bsData["dk_accprofit_first"].asInt();
		tData.dk_videotype = bsData["dk_videotype"].asInt();
		tData.dk_mcid10060 = bsData["dk_mcid10060"].asInt();

		pResult->data = tData;

		pResult->bSuccess = tData.nId > 0;

		return pResult;
	}
}