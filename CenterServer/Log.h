#pragma once

#include <string>
using namespace std;

#include "tc/Def.h"
using namespace tc;

#include "log/LogSrv.h"
using namespace llog;

#include "hc/Log.h"
using namespace hc;

#include "db/Log.h"
using namespace db;



// Log type
enum class ELogType : int
{
	Info,
	Debug,
	Warn,
	Error,
	Fatal,
	Exception
};

// Log Service
class Log final
{
private:
	Log();

public:
	//************************************
	// Method:    ELogType to ELogSrvType
	// Parameter: ELogType type
	//************************************
	static ELogSrvType ELogType_2_ELogSrvType(ELogType type);

	//************************************
	// Method:    ETcpLogType to ELogSrvType
	// Parameter: ETcpLogType type
	//************************************
	static ELogSrvType ETcpLogType_2_ELogSrvType(ETcpLogType type);

	//************************************
	// Method:    ETcpLogType to ELogType
	// Parameter: ETcpLogType type
	//************************************
	static ELogType ETcpLogType_2_ELogType(ETcpLogType type);

	//************************************
	// Method:    EHttpClientLogType to ELogSrvType
	// Parameter: EHttpClientLogType type
	//************************************
	static ELogSrvType EHttpClientLogType_2_ELogSrvType(EHttpClientLogType type);

	//************************************
	// Method:    EHttpClientLogType to ELogType
	// Parameter: EHttpClientLogType type
	//************************************
	static ELogType EHttpClientLogType_2_ELogType(EHttpClientLogType type);

	//************************************
	// Method:    EDbLogType to ELogSrvType
	// Parameter: EDbLogType type
	//************************************
	static ELogSrvType EDbLogType_2_ELogSrvType(EDbLogType type);
	
	//************************************
	// Method:    EDbLogType to ELogType
	// Parameter: EDbLogType type
	//************************************
	static ELogType EDbLogType_2_ELogType(EDbLogType type);

	//************************************
	// Method:    Print
	// Parameter: ELogType type
	// Parameter: string format
	//************************************
	static void Printf(ELogType type, string format, ...);
};

// type:			ELogType
// bOutput2Console:	whether output to console
// format:			format
#define WriteLog(type, bOutput2Console, format, ...)			if(bOutput2Console){Log::Printf((type), (format), __VA_ARGS__);} LogSrv::WriteLine(Log::ELogType_2_ELogSrvType(type), (format), __VA_ARGS__);