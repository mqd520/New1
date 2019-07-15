#include "stdafx.h"
#include "Include/db/Log.h"

#define MaxLogBufLen		(1024)			// max log buf len

namespace db
{
	DbLogCallback DbLog::fn;


	DbLog::DbLog()
	{

	}

	void DbLog::WriteLine(EDbLogType type, bool bOutputConsole, string format, ...)
	{
		char log[MaxLogBufLen] = { 0 };
		va_list argPtr;
		va_start(argPtr, format);
		vsprintf_s(log, MaxLogBufLen - 1, format.c_str(), argPtr);
		va_end(argPtr);

		if (!DbLog::fn._Empty())
		{
			DbLog::fn(type, log, bOutputConsole);
		}
	}

	void DbLog::SetCallbackFn(DbLogCallback fn)
	{
		DbLog::fn = fn;
	}
}