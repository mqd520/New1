#pragma once

#include "CenterCommonService.h"

// Plaza Service
class PlazaService : public CenterCommonService
{
public:
	PlazaService(string ip = "", int port = 0);
	~PlazaService();

protected:
	//************************************
	// Method:    处理登录服务端处理结果
	// Parameter: PacketData & data
	// Parameter: success: 是否成功
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;

	//************************************
	// Method:    包处理
	// Parameter: PacketData & pd
	//************************************
	virtual void OnProcessPck(PacketData& pd) override;

	//************************************
	// Method:    ServerListenExPacket包处理程序
	// Parameter: PacketData & pd
	//************************************
	virtual void OnServerListenEx(PacketData& pd);
};