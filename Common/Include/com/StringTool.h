#pragma once

#include <string>
#include <vector>
using namespace std;

namespace com
{
	// string tool
	class StringTool final
	{
	private:
		StringTool();

	public:
		static void Split(const string& strSrc, vector<string>& vec, const string& strFind);

		static string ToLower(string& str);

		static string ToUpper(string& str);

		static string UTF16_2_GB2312(wchar_t* pStr);

		static string UTF16_2_UTF8(wchar_t* pStr);

		static wstring GB2312_2_UTF16(char* pStr);

		static string GB2312_2_UTF8(char* pStr);

		static wstring UTF8_2_UTF16(char* pStr);

		static string UTF8_2_GB2312(char* pStr);
	};
}