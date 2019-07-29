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

		pResult->nGameRoundId = bsData["gmid"].asInt();
		if (pResult->nGameRoundId > 0)
		{
			pResult->strGameRoundNo = IsUTF8(data) ? UTF8_2_GB2312(bsData["gmnumber"].asString()) : bsData["gmnumber"].asString();
			pResult->nXue = bsData["xue"].asInt();
			pResult->nPu = bsData["pu"].asInt();
			pResult->nDuplicateId = bsData["DuplicateID"].asInt();
			pResult->bIsNewXue = bsData["NX"].asBool();
		}

		pResult->bSuccess = true;

		return pResult;
	}
}