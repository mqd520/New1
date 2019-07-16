#include "stdafx.h"
#include "Log.h"

#include "log/LogSrv.h"
using namespace llog;


Log::Log()
{

}

void Log::Init()
{
	LogSrv::Init();

	LogSrv::WriteLine(ELogSrvType::Info, "This is a test.");
}