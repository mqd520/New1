#pragma once

#include <string>
#include <vector>
using namespace std;


#define GB2312EndCharByteLen	(1)		// length of GB2312 end char 
#define UTF16EndCharByteLen		(2)		// length of UTF16 end char 
#define UTF8EndCharByteLen		(1)		// length of UTF8 end char 


namespace com
{
	// string tool
	class StringTool final
	{
	private:
		StringTool();

	public:
		//************************************
		// Method:    Split
		// Parameter: const string & strSrc
		// Parameter: vector<string> & vec
		// Parameter: const string & strFind
		//************************************
		static void Split(const string& strSrc, vector<string>& vec, const string& strFind);

		//************************************
		// Method:    To Lower String
		// Parameter: string & str
		//************************************
		static string ToLower(string& str);

		//************************************
		// Method:    To Upper String
		// Parameter: string & str
		//************************************
		static string ToUpper(string& str);

		//************************************
		// Method:    Trim
		// Parameter: string & str
		//************************************
		static void Trim(string& str);

		//************************************
		// Method:    UTF16 to GB2312
		// Parameter: wchar_t * pStr
		//************************************
		static string UTF16_2_GB2312(wchar_t* pStr);

		//************************************
		// Method:    UTF16 to UTF8
		// Parameter: wchar_t * pStr
		//************************************
		static string UTF16_2_UTF8(wchar_t* pStr);

		//************************************
		// Method:    GB2312 to UTF16
		// Parameter: char * pStr
		//************************************
		static wstring GB2312_2_UTF16(char* pStr);

		//************************************
		// Method:    GB2312 to UTF8
		// Parameter: char * pStr
		//************************************
		static string GB2312_2_UTF8(char* pStr);

		//************************************
		// Method:    UTF8 to UTF16
		// Parameter: char * pStr
		//************************************
		static wstring UTF8_2_UTF16(char* pStr);

		//************************************
		// Method:    UTF8 to GB2312
		// Parameter: char * pStr
		//************************************
		static string UTF8_2_GB2312(char* pStr);

		static void GetGB2312StrLen(char* pStr, int* charLen = nullptr, int* byteLen = nullptr);

		static void GetUTF16StrLen(wchar_t* pStr, int* charLen = nullptr, int* byteLen = nullptr);

		static void GetUTF8StrLen(char* pStr, int* charLen = nullptr, int* byteLen = nullptr);
	};
}