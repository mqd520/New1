#include "stdafx.h"

#include "Include/hc/HttpRequestMgr.h"
#include "Include/hc/HttpClientApp.h"
#include "CommonTool.h"
#include "Include/hc/Log.h"

#include <assert.h>
#include <tchar.h>
#include <minwinbase.h>

#include "ryeol/RyeolHttpClient.h"
using namespace Ryeol;


#define MaxRecvBufLen	(8096)		// 最大接收缓冲区长度


// http header list
static const TCHAR* _headers[] = {
	_T("Content-Length"), _T("Content-Type"),
	_T("Server"), _T("Date"), _T("X-Powered-By"), _T("Accpet-ranges"), _T("Content-Encoding"), _T("Age"), _T("Expires"), _T("Last-modified"), _T("Vary")
	_T("Connection"), _T("Cache-control"), _T("Expires"), _T("Set-Cookie"), _T("Transfer-Encoding")
};
static const int _nHeaderCount = sizeof(_headers) / sizeof(TCHAR*);		// http header count


namespace hc
{
	HttpRequestMgr::HttpRequestMgr() :
		bExited(false)
	{
		InitializeCriticalSection(&section1);
	}

	HttpRequestMgr::~HttpRequestMgr()
	{
		DeleteCriticalSection(&section1);
	}

	void HttpRequestMgr::Push(HttpRequestParaInfo& info)
	{
		EnterCriticalSection(&section1);

		if (!bExited)
		{
			quHttpRequests.push(info);
		}

		LeaveCriticalSection(&section1);
	}

	void HttpRequestMgr::ProcessRequest(HttpRequestParaInfo& info)
	{
		HttpClient* phc = HttpClientApp::GetHttpClientMgr()->Get(info.url1);
		if (phc)
		{
			CHttpClient http;
			CHttpResponse* response = NULL;


			string params = "";
			for (vector<pair<string, string>>::iterator it = info.vecParams.begin(); it != info.vecParams.end(); it++)
			{
				params += it->first + "=" + it->second + ", ";
			}
			HttpClientLog::WriteLine(EHttpClientLogType::Debug, false, "Prepare to send http request, url: %s, paras: %s",
				info.url1.c_str(), params.c_str());


			if (info.method == "GET")
			{

#if _UNICODE
				wstring urlUTF16 = CommonTool::GB2312_2_UTF16((char*)info.url.c_str());

				try
				{
					response = http.RequestGet(urlUTF16.c_str());
				}
				catch (CHttpClient::Exception& e)
				{
					string errmsg = CommonTool::UTF16_2_GB2312((wchar_t*)e.errmsg());
					HttpClientLog::WriteLine(EHttpClientLogType::Error, true,
						"Send http request fail, error code: %d, win32 error code: %d, err msg: %s,  url: %s, paras: %s",
						e.LastError(), e.Win32LastError(), errmsg.c_str(), info.url1.c_str(), params.c_str());

					return;
				}

#else
				response = http.RequestGet(info.url.c_str());
#endif

			}
			else if (info.method == "POST")
			{

				for (vector<pair<string, string>>::iterator it = info.vecParams.begin(); it != info.vecParams.end(); it++)
				{
#if _UNICODE
					wstring key = CommonTool::GB2312_2_UTF16((char*)it->first.c_str());
					wstring val = CommonTool::GB2312_2_UTF16((char*)it->second.c_str());
					http.AddParam(key.c_str(), val.c_str());
#else
					http.AddParam(it->first.c_str(), it->first.c_str());
#endif
				}

#if _UNICODE
				wstring urlUTF16 = CommonTool::GB2312_2_UTF16((char*)info.url.c_str());

				try
				{
					response = http.RequestPost(urlUTF16.c_str());
				}
				catch (CHttpClient::Exception& e)
				{
					string errmsg = CommonTool::UTF16_2_GB2312((wchar_t*)e.errmsg());
					HttpClientLog::WriteLine(EHttpClientLogType::Error, true,
						"Send http request fail, error code: %d, win32 error code: %d, err msg: %s,  url: %s, paras: %s",
						e.LastError(), e.Win32LastError(), errmsg.c_str(), info.url1.c_str(), params.c_str());

					return;
				}

#else
				response = http.RequestPost(info.url.c_str());
#endif

			}

			BYTE buf[MaxRecvBufLen] = { 0 };
			int len = response->ReadContent(buf, MaxRecvBufLen);

			HttpResponseData data;
			data.bufContent = (char*)buf;
			data.len = len;
			data.nStatusCode = (int)response->GetStatus();

			CHttpClient::PCSZ pcsz1 = response->GetHeader(_T("Content-Type"));
			if (pcsz1)
			{

#if _UNICODE
				data.strContentType = CommonTool::UTF16_2_GB2312(L"Content-Type");
#else
				data.strContentType = (char*)response->GetHeader("Content-Type");
#endif

			}

#if _UNICODE
			data.strStatusText = CommonTool::UTF16_2_GB2312((wchar_t*)response->GetStatusText());
#else
			data.strStatusText = (char*)response->GetStatusText();
#endif

			for (int i = 0; i < _nHeaderCount; i++)
			{
#if _UNICODE
				CHttpClient::PCSZ pcsz = response->GetHeader(_headers[i]);
				if (pcsz)
				{
					string headerVal1 = CommonTool::UTF16_2_GB2312((wchar_t*)pcsz);
					string headerKey1 = CommonTool::UTF16_2_GB2312((wchar_t*)_headers[i]);
					data.vecHeaders.push_back({ headerKey1, headerVal1 });
				}
#else
				CHttpClient::PCSZ pcsz = response->GetHeader(_headers[i]);
				if (pcsz)
				{
					data.vecHeaders.push_back({ (char*)_headers[i], pcsz });
				}
#endif
			}

			HttpResponseInfo info = { phc, data };
			HttpClientApp::GetHttpResponseMgr()->Push(info);
		}
	}

	void HttpRequestMgr::ProcessHttpRequest()
	{
		while (!bExited)
		{
			EnterCriticalSection(&section1);

			if (!quHttpRequests.empty())
			{
				HttpRequestParaInfo info = quHttpRequests.front();
				assert(!quHttpRequests.empty());
				quHttpRequests.pop();

				LeaveCriticalSection(&section1);

				ProcessRequest(info);
			}
			else
			{
				LeaveCriticalSection(&section1);
				break;
			}
		}
	}

	void HttpRequestMgr::Exit()
	{
		bExited = true;

		while (!quHttpRequests.empty())
		{
			quHttpRequests.pop();
		}
	}
}