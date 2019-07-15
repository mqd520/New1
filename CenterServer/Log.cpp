#include "stdafx.h"
#include "Log.h"


#define		CS_MaxLogLen					(1024)											// max log length
#define		CS_Printf(p1, p2, ...)			Log::Printf(p1, p2, __VA_ARGS__)				// Log::Printf


Log::Log()
{

}

ELogSrvType Log::ELogType_2_ELogSrvType(ELogType type)
{
	ELogSrvType type1 = (ELogSrvType)type;

	return type1;
}

ELogSrvType Log::ETcpLogType_2_ELogSrvType(ETcpLogType type)
{
	ELogSrvType type1 = (ELogSrvType)type;

	return type1;
}

ELogType Log::ETcpLogType_2_ELogType(ETcpLogType type)
{
	ELogType type1 = (ELogType)type;

	return type1;
}

ELogSrvType Log::EHttpClientLogType_2_ELogSrvType(EHttpClientLogType type)
{
	ELogSrvType type1 = (ELogSrvType)type;

	return type1;
}

ELogType Log::EHttpClientLogType_2_ELogType(EHttpClientLogType type)
{
	ELogType type1 = (ELogType)type;

	return type1;
}

ELogSrvType Log::EDbLogType_2_ELogSrvType(EDbLogType type)
{
	ELogSrvType type1 = (ELogSrvType)type;

	return type1;
}

ELogType Log::EDbLogType_2_ELogType(EDbLogType type)
{
	ELogType type1 = (ELogType)type;

	return type1;
}

void Log::Printf(ELogType type, string format, ...)
{
	SYSTEMTIME t;
	GetLocalTime(&t);

	char log[CS_MaxLogLen] = { 0 };
	va_list argPtr;
	va_start(argPtr, format);
	vsprintf_s(log, CS_MaxLogLen - 1, format.c_str(), argPtr);
	va_end(argPtr);

	string title = "None";
	if (type == ELogType::Info)
	{
		title = "Infor";
	}
	else if (type == ELogType::Debug)
	{
		title = "Debug";
	}
	else if (type == ELogType::Warn)
	{
		title = " Warn";
	}
	else if (type == ELogType::Error)
	{
		title = "Error";
	}
	else if (type == ELogType::Fatal)
	{
		title = "Fatal";
	}
	else if (type == ELogType::Exception)
	{
		title = "Excep";
	}

	char ch[CS_MaxLogLen] = { 0 };
	sprintf_s(ch, "[%s] [%02d-%02d-%02d %02d:%02d:%02d.%03d] %s", title.c_str(), t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds, log);


	WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	if (type == ELogType::Debug)
	{
		color = FOREGROUND_BLUE | FOREGROUND_GREEN;
	}
	else if (type == ELogType::Warn)
	{
		color = FOREGROUND_RED | FOREGROUND_GREEN;
	}
	else if (type == ELogType::Error)
	{
		color = FOREGROUND_RED;
	}
	else if (type == ELogType::Fatal || type == ELogType::Exception)
	{
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf("%s\n", ch);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}