#pragma once

#include "Def.h"
#include "DbParameter.h"

#include <string>
#include <vector>
using namespace std;

#include "hc/HttpClientApp.h"
#include "hc/HttpClient.h"
using namespace hc;

#include "json/json.h"
using namespace Json;


namespace db
{
	class DbService;

	// db execute success callback fn
	typedef std::function<void(DbService*, DbResult*)> DbExecuteSuccessCallback;

	// database service
	class DbService
	{
	public:
		//************************************
		// Method:    constructor
		// Parameter: string controller
		// Parameter: string action
		//************************************
		DbService(string controller, string action);

		//************************************
		// Method:    constructor
		// Parameter: string addr: http request addr
		//************************************
		DbService(string addr);

		//************************************
		// Method:    destructor
		//************************************
		virtual ~DbService();

	protected:
		string strAddr;			// http request addr
		HttpClient hc;			// http client obj
		DbExecuteSuccessCallback fn;	// db execute success callback fn

	protected:
		//************************************
		// Method:    http response event handler
		// Parameter: HttpClient * phc
		// Parameter: HttpResponseData & data
		//************************************
		virtual void OnHttpResponse(HttpClient* phc, HttpResponseData& data);

		//************************************
		// Method:    parse db result
		// Parameter: HttpResponseData & data
		//************************************
		virtual DbResult* ParseDbResult(HttpResponseData& data);

		//************************************
		// Method:    process db result
		// Parameter: DbResult * pResult
		//************************************
		virtual void ProcessDbResult(DbResult* pResult);

	public:
		//************************************
		// Method:    Get db service addr
		//************************************
		string GetAdrr();

		//************************************
		// Method:    Reset db service addr
		// Parameter: string addr
		//************************************
		void ResetAddr(string addr);

		//************************************
		// Method:    set db execute success callback fn
		// Parameter: DbExecuteSuccessCallback fn
		//************************************
		void SetDbCallback(DbExecuteSuccessCallback fn);

		//************************************
		// Method:    execute db request
		// Parameter: DbParameter * pParam
		//************************************
		void ExecuteQuery(DbParameter* pParam = NULL);
	};
}