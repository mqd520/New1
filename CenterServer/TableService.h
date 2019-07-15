#pragma once

#include "CenterCommonService.h"

// Table Service
class TableService : public CenterCommonService
{
public:
	TableService(string ip = "", int port = 0);
	~TableService();

protected:
	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};