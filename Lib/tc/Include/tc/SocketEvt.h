#pragma once
#include "Def.h"

namespace tc
{
	// socket�¼�(����)
	class SocketEvt
	{
	public:
		SocketEvt();
		virtual ~SocketEvt();

	protected:
		ESocketEvtType evtType;		// socket�¼�����

	public:
		//************************************
		// Method:    ��ȡ�¼�����
		//************************************
		ESocketEvtType GetEvtType() const;
	};
}