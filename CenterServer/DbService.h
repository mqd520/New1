#pragma once

#include "CenterCommonService.h"

// Db Service
class DbService : public CenterCommonService
{
public:
	DbService(string ip = "", int port = 0);
	~DbService();

protected:
	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};