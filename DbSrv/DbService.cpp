#include "stdafx.h"
#include "Include/db/DbService.h"
#include "Include/db/DbServiceApp.h"
#include "Include/db/Log.h"

#include "com/StringTool.h"
using namespace com;

#include "json/json.h"
using namespace Json;


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
		Json::Value root;
		Json::Reader reader;
		reader.parse(data.bufContent, root);

		int code = root["code"].asInt();
		if (code == 0)	// request db success
		{
			DbResult* pResult = ParseDbResult(data);
			if (pResult)
			{
				if (pResult->bSuccess)
				{
					ProcessDbResult(pResult);
				}

				delete pResult;
			}
		}
		else
		{
			DbLog::WriteLine(EDbLogType::Error, true, "request db fail, code: %d, json: %s", code, data.bufContent.c_str());
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

	bool DbService::IsUTF8(HttpResponseData& data)
	{
		bool b = true;

		for (vector<pair<string, string>>::iterator it = data.vecHeaders.begin(); it != data.vecHeaders.end(); it++)
		{
			string str = StringTool::ToLower(it->first);
			if (str == "content-type")
			{
				string str1 = StringTool::ToLower(it->second);
				int pos = str1.find("utf-8");
				b = pos >= 0;
				break;
			}
		}

		return b;
	}

	string DbService::UTF8_2_GB2312(string str)
	{
		return StringTool::UTF8_2_GB2312((char*)str.c_str());
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

	void DbService::ExecuteQuery(string method, DbParameter* pParam, string query, string contentType)
	{
		if (method == "POST")
		{
			vector<pair<string, string>> vec;
			if (pParam != NULL)
			{
				pParam->GetParams(vec);
			}

			hc.HttpPost(vec, query, contentType);
		}
		else if (method == "GET")
		{
			hc.HttpGet(query, contentType);
		}
		else
		{
			DbLog::WriteLine(EDbLogType::Error, true, "Http method not support: %s", method.c_str());
		}
	}

	void DbService::ExecuteQuery(DbParameter* pParam, string query)
	{
		ExecuteQuery("POST", pParam, query, "application/x-www-form-urlencoded");
	}

	void DbService::ExecuteQuery(DbParameter* pParam)
	{
		ExecuteQuery(pParam, "");
	}

	void DbService::ExecuteQuery()
	{
		ExecuteQuery(NULL);
	}

	void DbService::Exit()
	{

	}
}