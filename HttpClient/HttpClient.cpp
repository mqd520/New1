#include "stdafx.h"
#include "Include/hc/HttpClient.h"
#include "Include/hc/HttpClientApp.h"

#include "ryeol/RyeolHttpClient.h"
using namespace Ryeol;

namespace hc
{
	HttpClient::HttpClient(string url /*= ""*/) :
		url(url)
	{

	}

	HttpClient::~HttpClient()
	{

	}

	void HttpClient::OnHttpResponse(HttpResponseData& data)
	{
		if (!fn._Empty())
		{
			fn(this, data);
		}
	}

	void HttpClient::SetCallbackFn(HttpResponseCallback fun)
	{
		this->fn = fun;
	}

	string HttpClient::GetUrl()
	{
		return url;
	}

	void HttpClient::ResetUrl(string url)
	{
		this->url = url;
	}

	void HttpClient::HttpGet(string query /*= ""*/)
	{
		HttpClientApp::GetHttpClientMgr()->Add(this);

		string url1;
		if (!query.empty())
		{
			url1 = url + "?" + query;
		}
		else
		{
			url1 = url;
		}

		HttpRequestParaInfo info;
		info.url1 = url1;
		info.url = url;
		info.method = "GET";
		HttpClientApp::GetHttpRequestMgr()->Push(info);
	}

	void HttpClient::HttpPost(vector<pair<string, string>>& params, string query /*= ""*/)
	{
		HttpClientApp::GetHttpClientMgr()->Add(this);

		string url1;
		if (!query.empty())
		{
			url1 = url + "?" + query;
		}
		else
		{
			url1 = url;
		}

		HttpRequestParaInfo info;
		info.url1 = url1;
		info.url = url;
		info.method = "POST";
		info.vecParams = params;

		HttpClientApp::GetHttpRequestMgr()->Push(info);
	}

	void HttpClient::Exit()
	{
		HttpClientApp::GetHttpClientMgr()->Remove(this);
	}
}