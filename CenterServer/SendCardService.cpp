#include "stdafx.h"
#include "SendCardService.h"

SendCardService::SendCardService(string ip /*= ""*/, int port /*= 0*/) :
CenterCommonService(ip, port)
{

}

SendCardService::~SendCardService()
{

}

void SendCardService::ProcessLoginSrvResult(PacketData& data, bool success /*= true*/)
{
	__super::ProcessLoginSrvResult(data);
}