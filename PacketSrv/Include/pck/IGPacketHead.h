#pragma once
#include "PacketCmd.h"

#include "tc/PacketHead.h"
using namespace tc;

namespace pck
{
	// ig head
	class IGPacketHead : public PacketHead
	{
	public:
		IGPacketHead(int cmd = 0, int len = 0);

	protected:
		int nMask;		// ���
		int nCode;		// ������

	public:
		//************************************
		// Method:    �����ж�ȡ���ݵ�����
		// Parameter: ns:	ֻ������������
		//************************************
		virtual void Read(NetworkStreamRead& ns) override;

		//************************************
		// Method:    ������д������
		// Parameter: ns:	ֻд����������
		//************************************
		virtual void Write(NetworkStreamWrite& ns) override;

		//************************************
		// Method:    �Ƿ����
		//************************************
		virtual bool IsValid() override;

		//************************************
		// Method:    ��ȡcode
		//************************************
		int GetCode();

		//************************************
		// Method:    ��ȡmask
		//************************************
		int GetMask();
	};
}