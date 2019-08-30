#include "stdafx.h"
#include "Include/db/ApplyGameRoundSrv.h"
#include "Include/db/Log.h"

#include "json/json.h"
using namespace Json;


namespace db
{
	ApplyGameRoundSrv::ApplyGameRoundSrv() :
		DbService("Game", "ApplyGameRound")
	{

	}

	ApplyGameRoundSrv::ApplyGameRoundSrv(string addr) :
		DbService(addr)
	{

	}

	DbResult* ApplyGameRoundSrv::ParseDbResult(HttpResponseData& data)
	{
		ApplyGameRoundResult* pResult = new ApplyGameRoundResult();

		Json::Value root;
		Json::Reader reader;
		reader.parse(data.bufContent, root);
		Json::Value bsData = root["data"];

		pResult->nGameRoundId = bsData["GameRoundId"].asInt();
		if (pResult->nGameRoundId > 0)
		{
			pResult->strGameRoundNo = IsUTF8(data) ? UTF8_2_GB2312(bsData["GameRoundNo"].asString()) : bsData["GameRoundNo"].asString();
			pResult->nXue = bsData["Xue"].asInt();
			pResult->nPu = bsData["Pu"].asInt();
			pResult->nDuplicateId = bsData["DuplicateId"].asInt();
			pResult->bIsNewXue = bsData["IsNewXue"].asBool();
		}

		pResult->bSuccess = true;

		return pResult;
	}
}