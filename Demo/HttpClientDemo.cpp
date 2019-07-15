#include "stdafx.h"
#include "HttpClientDemo.h"

#include "hc/HttpClientApp.h"
#include "hc/Log.h"
using namespace hc;


void OnLog(EHttpClientLogType type, string log, bool bOutputConsole);
void OnHttpResponse(HttpClient* phc, HttpResponseData& data);


HttpClientDemo::HttpClientDemo()
{

}

void HttpClientDemo::Demo()
{
	printf("HttpClientDemo. \n");


	// Init		---------------------------------------------------------
	HttpClientApp::Init();
	HttpClientLog::SetCallbackFn(std::bind(OnLog, _1, _2, _3));
	// Init		---------------------------------------------------------



	static HttpClient hc("127.0.0.1:8001");
	hc.SetCallbackFn(std::bind(OnHttpResponse, _1, _2));
	//hc.HttpGet();

	vector<pair<string, string>> vec;
	vec.push_back({ "string", "string" });
	hc.HttpPost(vec);
}

void OnLog(EHttpClientLogType type, string log, bool bOutputConsole)
{
	printf("OnLog: [%04d] %s \n", type, log.c_str());
}

void OnHttpResponse(HttpClient* phc, HttpResponseData& data)
{
	printf("OnHttpResponse: url: %s, status: %d, Content-Type: %s, content: %s \n",
		data.url, data.nStatusCode, data.strContentType, data.bufContent);
}