#pragma once

#include <string>
#include <map>
using namespace std;

namespace com
{
	// Http Request
	class HttpRequest
	{
	public:
		HttpRequest();
		~HttpRequest();

	public:
		string reqLine;			// request line
		string path;			// request path
		string fullPath;		// request full path
		string host;			// host
		int port;				// port
		string queryParam;		// query param string
		string method;			// request method
		string version;			// http version
		string contentType;		// Content-type
		string url;				// url

		int contentLen;			// request content len
		BYTE* pContentBuf;		// request content buf

		map<string, string> mapHeaders;		// http headers map

		bool bSuccess;			// parse http request success

	public:
		string GetReqHeaderValue(string header);

	public:
		static void Parse(HttpRequest& req, BYTE* pBuf, int len);
	};
}