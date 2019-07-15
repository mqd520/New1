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
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};