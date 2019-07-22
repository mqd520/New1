#include "stdafx.h"
#include "Config.h"
#include "Log.h"

#include "com/CommonTool.h"
using namespace com;

const Config _cfg(CommonTool::GetCurrentDir() + "Baccrat.ini");

Config::Config(string strFilePath) :
gamecenter(GameCenterSection(strFilePath)),
dbSrv(DbServiceSection(strFilePath)),
strFilePath(strFilePath)
{

}

void Config::Init() const
{
	WriteLog(ELogType::Info, true, "Config info: ");
	WriteLog(ELogType::Info, true, "Game center section: ip = %s, port = %d", gamecenter.strIp.c_str(), gamecenter.nPort);
	WriteLog(ELogType::Info, true, "Db service section, addr: %s", dbSrv.strDbSrvAddr.c_str());
}