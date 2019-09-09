#include "stdafx.h"
#include "Include/com/CommonTool.h"
#include <stdio.h>
#include <WinSock2.h>
#include <objbase.h>

namespace com
{
	CommonTool::CommonTool()
		= default;

	//int CommonTool::ConvertIP(string ip)
	//{
	//	return inet_addr(ip.c_str());
	//}

	//string CommonTool::ConvertIP(int ip)
	//{
	//	char buffer[50] = { 0 };

	//	BYTE* pucIP = (BYTE*)&ip;
	//	sprintf_s(buffer, 50, "%u.%u.%u.%u",
	//		pucIP[0], pucIP[1], pucIP[2], pucIP[3]);

	//	string str = buffer;

	//	return str;
	//}

	string CommonTool::GetCurrentDir()
	{
		string str = "";

		char chPath[MAX_PATH] = { 0 };

		GetModuleFileNameA(NULL, chPath, MAX_PATH);
		char* p = strrchr(chPath, '\\');
		if (p)
		{
			*(p+1) = 0;
		}
		str = chPath;

		return str;
	}

	string CommonTool::CreateGuid()
	{
		GUID guid;
		CoCreateGuid(&guid);
		static char ch[64] = { 0 };

		sprintf_s(
			ch,
			sizeof(ch),
			"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			guid.Data1, guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1],
			guid.Data4[2], guid.Data4[3],
			guid.Data4[4], guid.Data4[5],
			guid.Data4[6], guid.Data4[7]);

		return ch;
	}
}