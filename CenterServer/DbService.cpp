#include "stdafx.h"
#include "DbService.h"

DbService::DbService(string ip /*= ""*/, int port /*= 0*/) :
CenterCommonService(ip, port)
{

}

DbService::~DbService()
{

}

void DbService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}