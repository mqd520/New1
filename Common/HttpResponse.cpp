#include "stdafx.h"
#include "Include/com/HttpResponse.h"

namespace com
{
	HttpResponse::HttpResponse(int statusCode /*= 200*/, string statusText /*= ""*/) :
		nStatusCode(statusCode),
		strStatusText(statusText),
		pBuf(NULL),
		contentLen(0),
		version("HTTP/1.1")
	{
		mapHeaders.insert(pair<string, string>("Server", "Mqd.WebServer-1.1"));
	}

	HttpResponse::~HttpResponse()
	{

	}

	string HttpResponse::GetStatusText(int statusCode)
	{
		string text = "";

		if (strStatusText.empty())
		{
			switch (statusCode)
			{
			case  200:
				text = "OK";
				break;

			case  304:
				text = "Not Modified";
				break;

			case  404:
				text = "Not Found";
				break;
			}
		}
		else
		{
			text = strStatusText;
		}

		return text;
	}

	void HttpResponse::SetResponseHeader(string key, string val)
	{
		mapHeaders.insert(pair<string, string>(key, val));
	}

	string HttpResponse::GetResponseHeader(string key)
	{
		string result = "";

		map<string, string>::iterator it = mapHeaders.begin();
		while (it != mapHeaders.end())
		{
			if (it->first == key)
			{
				result = it->second;
				break;
			}

			it++;
		}

		return result;
	}

	string HttpResponse::RemoveResponseHeader(string key)
	{
		string result = "";

		map<string, string>::iterator it = mapHeaders.begin();
		while (it != mapHeaders.end())
		{
			if (it->first == key)
			{
				result = it->second;
				mapHeaders.erase(it);
				break;
			}

			it++;
		}

		return result;
	}

	void HttpResponse::RemoveResponseHeader()
	{
		mapHeaders.clear();
	}

	void HttpResponse::SetResponseContent(BYTE* pBuf, int len)
	{
		this->pBuf = pBuf;
		contentLen = len;
	}

	void HttpResponse::ResetStatusCode(int statusCode, string statusText)
	{
		nStatusCode = statusCode;
		strStatusText = statusText;
	}

	void HttpResponse::SetHttpVersion(string version)
	{
		this->version = version;
	}

	int HttpResponse::BuildBuf(BYTE* buf, int len, bool isAppendContentLen /*= true*/, bool isAppendContent /*= true*/)
	{
		int nBufLen = 0;

		char ch[1024] = { 0 };
		sprintf_s(ch, "%s %d %s", version.c_str(), nStatusCode, GetStatusText(nStatusCode).c_str());
		string line = ch;

		string response = line + "\r\n";

		if (isAppendContentLen)
		{
			char ch1[20] = { 0 };
			_itoa(contentLen, ch1, 10);
			mapHeaders.insert(pair<string, string>("Content-Length", ch1));
		}

		map<string, string>::iterator it = mapHeaders.begin();
		while (it != mapHeaders.end())
		{
			response += it->first + ": " + it->second + "\r\n";
			it++;
		}

		response += "\r\n";

		int len1 = response.size();
		if (len1 <= len)
		{
			memcpy(buf, response.c_str(), len1);
			nBufLen += len1;

			if (isAppendContent)
			{
				if (pBuf && contentLen > 0 && contentLen <= (len - len1))
				{
					memcpy(buf + len1, pBuf, contentLen);
					nBufLen += contentLen;
				}
			}
		}

		return nBufLen;
	}
}