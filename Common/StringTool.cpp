#include "stdafx.h"
#include "Include/com/StringTool.h"

namespace com
{
	StringTool::StringTool()
	{

	}

	void StringTool::Split(const string& strSrc, vector<string>& vec, const string& strFind)
	{
		string::size_type pos1, pos2;
		pos2 = strSrc.find(strFind);
		pos1 = 0;

		while (string::npos != pos2)
		{
			vec.push_back(strSrc.substr(pos1, pos2 - pos1));

			pos1 = pos2 + strFind.size();
			pos2 = strSrc.find(strFind, pos1);
		}

		if (pos1 != strSrc.length())
		{
			vec.push_back(strSrc.substr(pos1));
		}
	}

	string StringTool::ToLower(string& str)
	{
		string result = str;

		int len = result.size();
		for (int i = 0; i < len; i++)
		{
			if (result[i] >= 'A' && result[i] <= 'Z')
			{
				result[i] += 32;
			}
		}

		return result;
	}

	string StringTool::ToUpper(string& str)
	{
		string result = str;

		int len = result.size();
		for (int i = 0; i < len; i++)
		{
			if (result[i] >= 'a' && result[i] <= 'z')
			{
				result[i] -= 32;
			}
		}

		return result;
	}

	string StringTool::UTF16_2_GB2312(wchar_t* pStr)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, pStr, -1, NULL, 0, NULL, NULL);
		char* aStr = new char[len];
		WideCharToMultiByte(CP_ACP, 0, pStr, -1, aStr, len, NULL, NULL);

		string result = aStr;
		delete aStr;

		return result;
	}

	string StringTool::UTF16_2_UTF8(wchar_t* pStr)
	{
		int len = WideCharToMultiByte(CP_UTF8, 0, pStr, -1, NULL, 0, NULL, NULL);
		char* aStr = new char[len];
		WideCharToMultiByte(CP_UTF8, 0, pStr, -1, aStr, len, NULL, NULL);

		string result = aStr;
		delete aStr;

		return result;
	}

	wstring StringTool::GB2312_2_UTF16(char* pStr)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, pStr, -1, NULL, 0);
		wchar_t* wStr = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, pStr, -1, wStr, len);

		wstring result = wStr;
		delete wStr;

		return result;
	}

	string StringTool::GB2312_2_UTF8(char* pStr)
	{
		wstring wStr = GB2312_2_UTF16(pStr);
		return UTF16_2_UTF8((wchar_t*)wStr.c_str());
	}

	wstring StringTool::UTF8_2_UTF16(char* pStr)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, pStr, -1, NULL, 0);
		wchar_t* wStr = new WCHAR[len];
		MultiByteToWideChar(CP_UTF8, 0, pStr, -1, wStr, len);

		wstring result = wStr;
		delete wStr;

		return result;
	}

	string StringTool::UTF8_2_GB2312(char* pStr)
	{
		wstring wStr = UTF8_2_UTF16(pStr);
		return UTF16_2_GB2312((wchar_t*)wStr.c_str());
	}
}