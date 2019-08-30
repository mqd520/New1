#include "stdafx.h"
#include "Config.h"
#include "Log.h"

#include "com/CommonTool.h"
using namespace com;


const Config _cfg(CommonTool::GetCurrentDir() + "Baccrat.ini");

Config::Config(string strFilePath) :
gamecenter(GameCenterSection(strFilePath)),
dbSrv(DbServiceSection(strFilePath)),
table(TableSection(strFilePath)),

strFilePath(strFilePath)
{
	
}

void Config::Init() const
{
	Log::Printf(ELogType::Info, "Config info: ");
	Log::Printf(ELogType::Info, "Game center section: ip = %s, port = %d", gamecenter.strIp.c_str(), gamecenter.nPort);
	Log::Printf(ELogType::Info, "Db service section, addr: %s", dbSrv.strDbSrvAddr.c_str());
	Log::Printf(ELogType::Info, "Table section, name list: %s", table.strTableIds.c_str());
}