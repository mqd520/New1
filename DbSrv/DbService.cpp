#include "stdafx.h"
#include "Include/db/DbService.h"
#include "Include/db/DbServiceApp.h"

namespace db
{
	DbService::DbService(string controller, string action) :
		strAddr(
		DbServiceApp::GetDbSrvAddr() +
		(!controller.empty() ? ("/" + controller) : "") +
		(!action.empty() ? ("/" + action) : "")
		),
		hc(strAddr)
	{
		hc.SetCallbackFn(std::bind(&DbService::OnHttpResponse, this, _1, _2));
	}

	DbService::DbService(string addr) :
		strAddr(addr),
		hc(addr)
	{
		hc.SetCallbackFn(std::bind(&DbService::OnHttpResponse, this, _1, _2));
	}

	DbService::~DbService()
	{

	}

	void DbService::OnHttpResponse(HttpClient* phc, HttpResponseData& data)
	{
		DbResult* pResult = ParseDbResult(data);
		if (pResult)
		{
			ProcessDbResult(pResult);

			delete pResult;
		}
	}

	DbResult* DbService::ParseDbResult(HttpResponseData& data)
	{
		return NULL;
	}

	void DbService::ProcessDbResult(DbResult* pResult)
	{
		if (!fn._Empty())
		{
			fn(this, pResult);
		}
	}

	string DbService::GetAdrr()
	{
		return strAddr;
	}

	void DbService::ResetAddr(string addr)
	{
		this->strAddr = addr;
		hc.ResetUrl(addr);
	}

	void DbService::SetDbCallback(DbExecuteSuccessCallback fn)
	{
		this->fn = fn;
	}

	void DbService::ExecuteQuery(DbParameter* pParam /*= NULL*/)
	{
		vector<pair<string, string>> vec;
		pParam->GetParams(vec);

		hc.HttpPost(vec);
	}
}