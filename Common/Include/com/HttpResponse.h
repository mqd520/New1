#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

namespace com
{
	// Http Response
	class HttpResponse
	{
	public:
		HttpResponse(int statusCode = 200, string statusText = "");
		~HttpResponse();

	private:
		map<string, string> mapHeaders;		// http response header list
		int contentLen;						// response content byte len
		BYTE* pBuf;							// response content buf
		int nStatusCode;					// response status code
		string strStatusText;				// response status text
		string version;						// version

	private:
		string GetStatusText(int statusCode);

	public:
		void SetResponseHeader(string key, string val);

		string GetResponseHeader(string key);

		string RemoveResponseHeader(string key);

		void RemoveResponseHeader();

		void SetResponseContent(BYTE* pBuf, int len);

		void ResetStatusCode(int statusCode, string statusText);

		void SetHttpVersion(string version);

		int BuildBuf(BYTE* buf, int len, bool isAppendContentLen = true, bool isAppendContent = true);
	};
}