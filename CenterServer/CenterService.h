#pragma once

#include "DbService.h"
#include "SendCardService.h"
#include "TableService.h"
#include "PlazaService.h"
#include "BAAdminWebSiteService.h"
#include "ServerListenMgr.h"


#include "pck/IGPacket.h"
using namespace pck;


// Center Service
class CenterService final
{
private:
	CenterService();

private:
	DbService dbService;					// Db Service
	SendCardService scService;				// SendCard Service
	TableService tableService;				// Table Service
	PlazaService plazaSrv;					// Plaza Service
	BAAdminWebSiteService baService;		// backstage admin website service
	ServerListenMgr slMgr;					// ServerListePacket Mgr		

public:
	//************************************
	// Method:    Get the origin CenterService instance
	//************************************
	static CenterService* GetInstance();

public:
	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();

	//************************************
	// Method:    get Db service obj
	//************************************
	DbService* GetDbSrv();

	//************************************
	// Method:    get SendCard service obj
	//************************************
	SendCardService* GetSendCardSrv();

	//************************************
	// Method:    get Table service obj
	//************************************
	TableService* GetTableSrv();

	//************************************
	// Method:    get plaza service obj
	//************************************
	PlazaService* GetPlazaSrv();

	//************************************
	// Method:    get backstage admin website service obj
	//************************************
	BAAdminWebSiteService* GetBAAdminSebSiteSrv();

	//************************************
	// Method:    Get ServerListenPacket obj
	//************************************
	ServerListenMgr* GetServerListenPacketMgr();
};