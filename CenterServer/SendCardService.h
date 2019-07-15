#pragma once

#pragma once

#include "CenterCommonService.h"

// SendCard Service
class SendCardService : public CenterCommonService
{
public:
	SendCardService(string ip = "", int port = 0);
	~SendCardService();

protected:
	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};