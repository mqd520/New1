#include "stdafx.h"
#include "TableService.h"

TableService::TableService(string ip /*= ""*/, int port /*= 0*/) :
CenterCommonService(ip, port)
{

}

TableService::~TableService()
{

}

void TableService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}