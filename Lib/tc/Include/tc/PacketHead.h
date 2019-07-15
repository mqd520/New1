#pragma once
#include "NetworkStreamRead.h"
#include "NetworkStreamWrite.h"

namespace tc
{
	// ��ͷ���ඨ��
	class PacketHead
	{
	public:
		//************************************
		// Method:    ���캯��
		// Parameter: cmd:	������
		// Parameter: len:	���峤��
		//************************************
		PacketHead(int cmd, int len);

	protected:
		int nHeadLen;			// ��ͷ����
		int nCmd;				// ������
		int nLen;				// ������
		int nTotalLen;			// ���ܳ���

	public:
		//************************************
		// Method:    ��ȡ��ͷ����
		//************************************
		virtual int GetHeadLen();

		//************************************
		// Method:    ��ȡ���峤��
		//************************************
		virtual int GetPacketLen();

		//************************************
		// Method:    ��ȡ�ܳ���
		//************************************
		virtual int GetTotalLen();

		//************************************
		// Method:    ��ȡ������
		//************************************
		virtual int GetCmd();

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

		//************************************
		// Method:    �Ƿ����
		//************************************
		virtual bool IsValid();
	};
}