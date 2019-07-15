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
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;

	//************************************
	// Method:    ������
	// Parameter: PacketData & pd
	//************************************
	virtual void OnProcessPck(PacketData& pd) override;

	//************************************
	// Method:    ServerListenExPacket���������
	// Parameter: PacketData & pd
	//************************************
	virtual void OnServerListenEx(PacketData& pd);
};