#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"

namespace db
{
	// db log type
	enum class EDbLogType : int
	{
		Info,		// Info
		Warn,		// Warn
		Debug,		// Debug
		Error,		// Error
		Fatal,		// Fatal

		None		//None
	};
}