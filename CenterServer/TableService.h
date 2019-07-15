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
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};