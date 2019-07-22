#include "stdafx.h"
#include "Include/db/PlayerLoginSrv.h"
#include "Include/db/Log.h"

namespace db
{
	PlayerLoginSrv::PlayerLoginSrv() :
		DbService("Player", "Login")
	{

	}

	PlayerLoginSrv::PlayerLoginSrv(string addr) :
		DbService(addr)
	{

	}

	DbResult* PlayerLoginSrv::ParseDbResult(HttpResponseData& data)
	{
		PlayerLoginResult* pResult = new PlayerLoginResult();

		//Json::Value root;
		//Json::Reader reader;
		//reader.parse(data.bufContent, root);

		//pResult->bSuccess = true;
		//pResult->strAccount = root["account"].asString();

		//PlayerLoginResultPara* pPara = new PlayerLoginResultPara();
		//pPara->nCount = 2;
		//pPara->nA = 1;
		//pPara->str1 = "str1";

		//pResult->pParam = pPara;

		//DbLog::WriteLine(EDbLogType::Error, "parse ***** error, json: %s", data.bufContent.c_str());

		return pResult;
	}
}