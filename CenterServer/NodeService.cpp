#include "stdafx.h"
#include "NodeService.h"

NodeService::NodeService(string ip /*= ""*/, int port /*= 0*/) :
CenterCommonService(ip, port)
{

}

NodeService::~NodeService()
{

}

void NodeService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}