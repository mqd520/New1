#include "stdafx.h"
#include "Include/com/CommonTool.h"
#include <stdio.h>
#include <WinSock2.h>


namespace com
{
	CommonTool::CommonTool()
		= default;

	int CommonTool::ConvertIP(string ip)
	{
		return inet_addr(ip.c_str());
	}

	string CommonTool::ConvertIP(int ip)
	{
		char buffer[50] = { 0 };

		BYTE* pucIP = (BYTE*)&ip;
		sprintf_s(buffer, 50, "%u.%u.%u.%u",
			pucIP[0], pucIP[1], pucIP[2], pucIP[3]);

		string str = buffer;

		return str;
	}

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
}