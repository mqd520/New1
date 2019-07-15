#pragma once

#include "CenterCommonService.h"

// Db Service
class NodeService : public CenterCommonService
{
public:
	NodeService(string ip = "", int port = 0);
	~NodeService();

protected:
	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};