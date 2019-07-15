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
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};