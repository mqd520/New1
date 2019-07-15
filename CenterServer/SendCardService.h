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
	// Method:    �����¼����˴�����
	// Parameter: PacketData & data
	// Parameter: success: �Ƿ�ɹ�
	//************************************
	virtual void ProcessLoginSrvResult(PacketData& data, bool success = true) override;
};