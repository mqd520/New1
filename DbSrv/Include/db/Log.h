#pragma once

#include "Def.h"

#include <minwindef.h>
#include <functional>
using namespace std;
using namespace std::placeholders;


namespace db
{
	// DbLog Callback fn
	// EDbLogType:	Db Log Type
	// string:		Log
	// bool:		whether output to console
	typedef std::function<void(EDbLogType, string, bool)> DbLogCallback;


	// db log
	class DbLog final
	{
	private:
		DbLog();

	private:
		static DbLogCallback fn;	// callback

	public:
		//************************************
		// Method:    WriteLine
		// Parameter: EDbLogType type
		// Parameter: bool bOutputConsole:	whether output to console
		// Parameter: string format
		// Parameter: ...
		//************************************
		static void WriteLine(EDbLogType type, bool bOutputConsole, string format, ...);

		//************************************
		// Method:    set callback
		// Parameter: DbLogCallback fn
		//************************************
		static void SetCallbackFn(DbLogCallback fn);
	};
}