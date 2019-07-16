#include "stdafx.h"
#include "Config.h"
#include "Log.h"

#include "com/CommonTool.h"
using namespace com;

const Config _cfg(CommonTool::GetCurrentDir() + "PlazaServer.ini");

Config::Config(string strFilePath) :
sendcard(SendCardSection(strFilePath)),
table(TableSection(strFilePath)),
dbSrv(DbServiceSection(strFilePath)),
strFilePath(strFilePath)
{

}

void Config::Init() const
{
	WriteLog(ELogType::Info, true, "Config info: ");
	WriteLog(ELogType::Info, true, "SendCard section: ip = %s, port = %d", sendcard.strIp.c_str(), sendcard.nPort);
	WriteLog(ELogType::Info, true, "Table section: ip = %s, port = %d", table.strIp.c_str(), table.nPort);
	WriteLog(ELogType::Info, true, "Db service section, addr: %s", dbSrv.strDbSrvAddr.c_str());
}