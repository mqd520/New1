#include "stdafx.h"
#include "Include/com/HttpRequest.h"
#include <vector>
#include "Include/com/StringTool.h"

namespace com
{
	bool ParseReqLine(HttpRequest& req, string& line);
	bool ParseHttpHeader(HttpRequest& req, vector<string>& vec);

	HttpRequest::HttpRequest() :
		pContentBuf(NULL),
		contentLen(0)
	{

	}

	HttpRequest::~HttpRequest()
	{
		if (pContentBuf)
		{
			delete pContentBuf;
			pContentBuf = NULL;
		}
	}

	string HttpRequest::GetReqHeaderValue(string header)
	{
		map<string, string>::iterator it = mapHeaders.find(header);
		if (it != mapHeaders.end())
		{
			return it->second;
		}

		return "";
	}

	void HttpRequest::Parse(HttpRequest& req, BYTE* pBuf, int len)
	{
		char* str1 = (char*)pBuf;

		vector<string> vec;
		StringTool::Split(str1, vec, "\r\n");

		if ((int)vec.size() >= 4)
		{
			bool b1 = ParseReqLine(req, vec[0]);
			bool b2 = ParseHttpHeader(req, vec);

			if (b1 && b2)
			{
				req.bSuccess = true;
				req.url = "http://" + req.host + req.fullPath;
				if (req.contentLen > 0)
				{
					req.pContentBuf = new BYTE[req.contentLen];
					memcpy(req.pContentBuf, (BYTE*)vec[(int)vec.size() - 1].c_str(), req.contentLen);
				}
			}
		}
	}

	bool ParseReqLine(HttpRequest& req, string& line)
	{
		vector<string> vec;
		StringTool::Split(line, vec, " ");

		if ((int)vec.size() == 3)
		{
			string method = vec[0];
			if (method == "GET" || method == "POST")
			{
				req.method = method;
			}
			else
			{
				return false;
			}

			req.fullPath = vec[1];

			vector<string> vec1;
			StringTool::Split(vec[1], vec1, "?");
			if ((int)vec1.size() > 1)
			{
				req.path = vec1[0];
				req.queryParam = vec1[1];
			}
			else
			{
				req.path = vec[1];
				req.queryParam = "";
			}

			if (vec[2] == "HTTP/1.1" || vec[2] == "HTTP/1.0")
			{
				req.version = vec[2];
			}
			else
			{
				return false;
			}

			req.reqLine = line;

			return true;
		}

		return false;
	}

	bool ParseHttpHeader(HttpRequest& req, vector<string>& vec)
	{
		for (vector<string>::iterator it = vec.begin() + 1; it != vec.end() - 1; it++)
		{
			if ((*it).empty())
			{
				break;
			}

			vector<string> vec1;
			StringTool::Split(*it, vec1, ": ");

			string key = vec1[0];
			string value = vec1[1];

			req.mapHeaders.insert(pair<string, string>(key, value));

			if (key == "Host")
			{
				req.host = value;

				vector<string> vec2;
				StringTool::Split(value, vec2, ":");
				if ((int)vec2.size() > 1)
				{
					req.port = atoi(vec2[1].c_str());
				}
				else
				{
					req.port = 80;
				}
			}
			else if (key == "Content-type")
			{
				req.contentType = value;
			}
			else if (key == "Content-Length")
			{
				req.contentLen = atoi(value.c_str());
			}
		}

		return true;
	}
}