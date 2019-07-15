#pragma once

#include <vector>
#include "NCTool.h"

using namespace std;

namespace tc
{
	/************************************************************************/
	/* ������(ֻд)��
	/************************************************************************/
	class NetworkStreamWrite
	{
	public:
		//************************************
		// Parameter: BYTE * pBuf:		������ָ��
		// Parameter: int len:			����������
		// Parameter: EByteOrder bo:	��������ʹ�õ��ֽ��� 	
		//************************************
		NetworkStreamWrite(BYTE* pBuf, int len, EByteOrder bo = EByteOrder::big);
		~NetworkStreamWrite();

	private:
		EByteOrder nsByteOrder;		// ��ǰ������ʹ�õ��ֽ���
		int nBuffLen;				// ����������
		BYTE* pBuff;				// ������
		int nWriteIndex;			// ����д����

	private:
		//************************************
		// Method:    д������
		// Returns:   �Ƿ�д��ɹ�
		// Parameter: void* pDest:	���ݵ�ַ
		// Parameter: int len:		�����ֽڳ���
		//************************************
		bool WriteData(void* pData, int len);

		//************************************
		// Method:    д���ַ���ǰ׺
		// Returns:   �Ƿ�д��ɹ�
		// Parameter: int prefix��	ǰ׺��ռ���ֽڳ���
		// Parameter: int len��		�ַ����ֽڳ���
		//************************************
		void WriteStrPrefix(int prefix, int len);

	public:
		//************************************
		// Method:    ���ػ���������
		//************************************
		int GetLen();

		//************************************
		// Method:    ���ػ�����ָ��
		//************************************
		BYTE* GetBuf();

		//************************************
		// Method:    ���ؿ�д���ֽ���
		//************************************
		int AvaliableWrite();

		//************************************
		// Method:    ������д�ֽ���
		//************************************
		int WritedCount();

		//************************************
		// Method:    д��һ�λ���������
		// Returns:	  �Ƿ�д��ɹ�
		// Parameter: BYTE* pBuf:	���ݻ�����
		// Parameter: int len:		���ݻ���������
		//************************************
		bool WriteBuf(BYTE* pBuf, int len);

		//************************************
		// Method:    д��һ�� BYTE ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteByte(BYTE val);

		//************************************
		// Method:    д��һ�� short ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteShort(short val);

		//************************************
		// Method:    д��һ�� USHORT ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteUShort(USHORT val);

		//************************************
		// Method:    д��һ�� INT16 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteInt16(INT16 val);

		//************************************
		// Method:    д��һ�� UINT16 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteUInt16(UINT16 val);

		//************************************
		// Method:    д��һ�� INT32 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteInt32(INT32 val);

		//************************************
		// Method:    д��һ�� UINT32 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteUInt32(UINT32 val);

		//************************************
		// Method:    д��һ�� INT64 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteInt64(INT64 val);

		//************************************
		// Method:    д��һ�� UINT64 ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteUInt64(UINT64 val);

		//************************************
		// Method:    д��һ�� float ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteFloat(float val);

		//************************************
		// Method:    д��һ�� double ����
		// Returns:	  �Ƿ�д��ɹ�
		//************************************
		bool WriteDouble(double val);

		//************************************
		// Method:    д�� GB2312 �ַ���
		// Returns:	  �Ƿ�д��ɹ�
		// Parameter: string str:		GB2312 �ַ���
		// Parameter: int prefix:		�ַ����ֽڳ���ǰ׺��ռ�ֽ�, ��Χ: 1, 2, 4, 0: ��ʹ��ǰ׺
		// Parameter: bool hasEndChar:	�Ƿ񽫽�����д��
		// Parameter: bool isPrefixContainEndChar:	ǰ׺��ֵ�Ƿ����������
		//************************************
		bool WriteGB2312Str(string str, int prefix = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);

		//************************************
		// Method:    д�� UTF16 �ַ���
		// Returns:	  �Ƿ�д��ɹ�
		// Parameter: string str:		UTF16 �ַ���
		// Parameter: int prefix:		�ַ����ֽڳ���ǰ׺��ռ�ֽ�, ��Χ: 1, 2, 4, 0: ��ʹ��ǰ׺
		// Parameter: bool hasEndChar:	�Ƿ񽫽�����д��
		// Parameter: bool isPrefixContainEndChar:	ǰ׺��ֵ�Ƿ����������
		//************************************
		bool WriteUTF16Str(wstring str, int prefix = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);

		//************************************
		// Method:    д�� UTF8 �ַ���
		// Returns:	  �Ƿ�д��ɹ�
		// Parameter: string str:		UTF8 �ַ���
		// Parameter: int prefix:		�ַ����ֽڳ���ǰ׺��ռ�ֽ�, ��Χ: 1, 2, 4, 0: ��ʹ��ǰ׺
		// Parameter: bool hasEndChar:	�Ƿ񽫽�����д��
		// Parameter: bool isPrefixContainEndChar:	�Ƿ񽫽�����д��
		//************************************
		bool WriteUTF8Str(string str, int prefix = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);
	};
}