#pragma once
#include "NetworkStreamRead.h"
#include "NetworkStreamWrite.h"

namespace tc
{
	// �������
	class Packet
	{
	public:
		Packet(int cmd);

	protected:
		int pckCmd;		// ������

	public:
		//************************************
		// Method:    ��ȡ������
		//************************************
		virtual int GetCmd();

		//************************************
		// Method:    ��ȡ������(������ͷ)
		//************************************
		virtual int GetLen();

		//************************************
		// Method:    �����ж�ȡ���ݵ�����
		// Parameter: ns:	ֻ������������
		//************************************
		virtual void Read(NetworkStreamRead& ns);

		//************************************
		// Method:    �����ж�ȡ���ݵ�����
		// Parameter: pBuf:	������
		// Parameter: len:	����������
		// Parameter: bigEndian:	�Ƿ�ʹ�ô���ֽ���
		//************************************
		virtual void Read1(BYTE* pBuf, int len, bool bigEndian = true);

		//************************************
		// Method:    ������д������
		// Parameter: ns:	ֻд����������
		//************************************
		virtual void Write(NetworkStreamWrite& ns);

		//************************************
		// Method:    ������д������
		// Parameter: pBuf:	������
		// Parameter: len:	����������
		// Parameter: bigEndian:	�Ƿ�ʹ�ô���ֽ���
		//************************************
		virtual void Write1(BYTE* pBuf, int len, bool bigEndian = true);
	};
}