#include "stdafx.h"
#include "CenterService.h"
#include "Log.h"
#include "Config.h"

#include "tc/SocketTool.h"
using namespace tc;


CenterService* pInstance = NULL;	// the unique CenterService instance

CenterService::CenterService()
{

}

CenterService* CenterService::GetInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new CenterService();
	}

	return pInstance;
}

void CenterService::Init()
{
	WriteLog(ELogType::Info, true, "Start to run CenterService");

	dbService.Init();
	dbService.SetListenInfo(_cfg.db.strIp, _cfg.db.nPort);
	bool b1 = dbService.Listen();
	if (b1)
	{
		WriteLog(ELogType::Info, true, "Listen Db Service success: %s:%d", _cfg.db.strIp.c_str(), _cfg.db.nPort);
	}

	//scService.Init();
	//scService.SetListenInfo(_cfg.sendcard.strIp, _cfg.sendcard.nPort);
	//bool b2 = scService.Listen();
	//if (b2)
	//{
	//	WriteLine1(ELogType::Info, true, "Listen SendCard Service success: %s:%d", _cfg.sendcard.strIp.c_str(), _cfg.sendcard.nPort);
	//}

	//tableService.Init();
	//tableService.SetListenInfo(_cfg.table.strIp, _cfg.table.nPort);
	//bool b3 = tableService.Listen();
	//if (b3)
	//{
	//	WriteLine1(ELogType::Info, true, "Listen Table Service success: %s:%d", _cfg.table.strIp.c_str(), _cfg.table.nPort);
	//}

	plazaSrv.Init();
	plazaSrv.SetListenInfo(_cfg.plaza.strIp, _cfg.plaza.nPort);
	bool b4 = plazaSrv.Listen();
	if (b4)
	{
		WriteLog(ELogType::Info, true, "Listen Plaza Service success: %s:%d", _cfg.plaza.strIp.c_str(), _cfg.plaza.nPort);
	}

	baService.Init();
	baService.SetListenInfo(_cfg.ba.strIp, _cfg.ba.nPort);
	bool b5 = baService.Listen();
	if (b5)
	{
		WriteLog(ELogType::Info, true, "Listen backstage admin website Service success: %s:%d", _cfg.ba.strIp.c_str(), _cfg.ba.nPort);
	}

	//slMgr.Init();

	//bool b = b1 == true && b2 == true && b3 == true && b4 == true;

	//WriteLine1(b ? ELogType::Info : ELogType::Error, true, "Run CenterService %s", b ? "success" : "fail");
}

void CenterService::Exit()
{
	dbService.Exit();
	scService.Exit();
	tableService.Exit();
	plazaSrv.Exit();
	baService.Exit();
	slMgr.Exit();
}

DbService* CenterService::GetDbSrv()
{
	return &dbService;
}

SendCardService* CenterService::GetSendCardSrv()
{
	return &scService;
}

TableService* CenterService::GetTableSrv()
{
	return &tableService;
}

PlazaService* CenterService::GetPlazaSrv()
{
	return &plazaSrv;
}

BAAdminWebSiteService* CenterService::GetBAAdminSebSiteSrv()
{
	return &baService;
}

ServerListenMgr* CenterService::GetServerListenPacketMgr()
{
	return &slMgr;
}