#include "stdafx.h"

#include "InitService.h"
#include "Log.h"
#include "Config.h"
#include "CenterService.h"

#include "com/ExceptionHandler.h"
using namespace com;

#include "log/LogSrv.h"
using namespace llog;

#include "tc/TcpCommuMgr.h"
#include "tc/Log.h"
using namespace tc;

#include "hc/HttpClientApp.h"
#include "hc/Log.h"
using namespace hc;

#include "db/DbServiceApp.h"
#include "db/Log.h"
using namespace db;



bool OnCtrlHandler(DWORD fdwctrltype);
void OnException(void* pParam1, void* pParam2);
void OnTcpLog(ETcpLogType type, string log, bool bOutput2Console);
void OnHttpClientLog(EHttpClientLogType type, string log, bool bOutput2Console);
void OnDbLog(EDbLogType type, string log, bool bOutput2Console);



InitService::InitService()
{

}

void InitService::OnMainRun()
{
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)OnCtrlHandler, true);

	ExceptionHandler::Init();
	ExceptionHandler::SetFileName("CenterServer.exe");
	ExceptionHandler::SetCallback(OnException);

	LogSrv::Init("CenterServer.exe.Log");

	_cfg.Init();

	TcpCommu::Init();
	TcpLog::SetCallbackFn(std::bind(OnTcpLog, _1, _2, _3));

	HttpClientApp::Init();
	HttpClientLog::SetCallbackFn(std::bind(OnHttpClientLog, _1, _2, _3));

	DbServiceApp::Init();
	DbServiceApp::SetDbSrvAddr(_cfg.dbSrv.strDbSrvAddr);
	DbLog::SetCallbackFn(std::bind(OnDbLog, _1, _2, _3));

	CenterService::GetInstance()->Init();
}

void InitService::OnMainExit()
{
	LogSrv::Exit();

	HttpClientApp::Exit();

	DbServiceApp::Exit();

	TcpCommu::Exit();

	CenterService::GetInstance()->Exit();
	delete CenterService::GetInstance();
}

bool OnCtrlHandler(DWORD fdwctrltype)
{
	bool b = false;

	switch (fdwctrltype)
	{
	case CTRL_C_EVENT:
		InitService::OnMainExit();
		break;

	case CTRL_CLOSE_EVENT:
		InitService::OnMainExit();
		break;
	}

	return b;
}

void OnException(void* pParam1, void* pParam2)
{
	LogSrv::Exit();
	TcpCommu::Exit();
}

void OnTcpLog(ETcpLogType type, string log, bool bOutput2Console)
{

	bool b = false;

	if (type == ETcpLogType::Debug || type == ETcpLogType::Exception)
	{
#if _DEBUG
		b = true;
#endif
	}
	else
	{
		b = true;
	}

	if (b && bOutput2Console)
	{
		Log::Printf(Log::ETcpLogType_2_ELogType(type), log);
	}
	LogSrv::WriteLine(Log::ETcpLogType_2_ELogSrvType(type), log);
}

void OnHttpClientLog(EHttpClientLogType type, string log, bool bOutput2Console)
{
	if (bOutput2Console)
	{
		Log::Printf(Log::EHttpClientLogType_2_ELogType(type), log);
	}
	LogSrv::WriteLine(Log::EHttpClientLogType_2_ELogSrvType(type), log);
}

void OnDbLog(EDbLogType type, string log, bool bOutput2Console)
{
	if (bOutput2Console)
	{
		Log::Printf(Log::EDbLogType_2_ELogType(type), log);
	}
	LogSrv::WriteLine(Log::EDbLogType_2_ELogSrvType(type), log);
}