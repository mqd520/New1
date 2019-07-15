#pragma once

#include <vector>
#include "NCTool.h"

using namespace std;

namespace tc
{
	/************************************************************************/
	/* ������(ֻ��)��
	/************************************************************************/
	class NetworkStreamRead
	{
	public:
		//************************************
		// Parameter: BYTE * pBuf:		������ָ��
		// Parameter: int len:			����������
		// Parameter: EByteOrder bo:	��������ʹ�õ��ֽ��� 	
		//************************************
		NetworkStreamRead(BYTE* pBuf, int len, EByteOrder bo = EByteOrder::big);
		~NetworkStreamRead();

	private:
		EByteOrder nsByteOrder;		// ��ǰ������ʹ�õ��ֽ���
		int nBuffLen;				// ����������
		BYTE* pBuff;				// ������
		int nReadIndex;				// ���ݶ�����

	private:
		//************************************
		// Method:    ��ȡ����
		// Returns:   �Ƿ��ȡ�ɹ�
		// Parameter: void * pData:	���ݵ�ַ
		// Parameter: int len:		�����ֽڳ���
		//************************************
		bool ReadData(void* pData, int len);

		//************************************
		// Method:    ��ȡ�ַ���ǰ׺
		// Returns:   int:	�ַ����ֽڳ���
		// Parameter: ǰ׺��ռ���ֽڳ���
		//************************************
		UINT32 ReadStrPrefix(int len);

	public:
		//************************************
		// Method:    �����ֽ���
		// Parameter: �ֽ���
		//************************************
		void SetByteOrder(EByteOrder bo);

		//************************************
		// Method:    ���ػ���������
		//************************************
		int GetLen();

		//************************************
		// Method:    ���ػ�����ָ��
		//************************************
		BYTE* GetBuf();

		//************************************
		// Method:    ���ؿɶ����ֽ���
		//************************************
		int AvaliableRead();

		//************************************
		// Method:    �����Ѷ��ֽ���
		//************************************
		int ReadedCount();

		//************************************
		// Method:    ��ȡһ�λ���������
		// Returns:	  ʵ�ʶ�ȡ����
		// Parameter: ���ջ�����
		// Parameter: Ԥ�ƶ�ȡ����
		//************************************
		int ReadBuf(BYTE* buf, int len);

		//************************************
		// Method:    ��ȡһ�� BYTE ����
		//************************************
		BYTE ReadByte();

		//************************************
		// Method:    ��ȡһ�� SHORT ����
		//************************************
		SHORT ReadShort();

		//************************************
		// Method:    ��ȡһ�� USHORT ����
		//************************************
		USHORT ReadUShort();

		//************************************
		// Method:    ��ȡһ�� INT16 ����
		//************************************
		INT16 ReadInt16();

		//************************************
		// Method:    ��ȡһ�� UINT16 ����
		//************************************
		UINT16 ReadUInt16();

		//************************************
		// Method:    ��ȡһ�� INT32 ����
		//************************************
		INT32 ReadInt32();

		//************************************
		// Method:    ��ȡһ�� UINT32 ����
		//************************************
		UINT32 ReadUInt32();

		//************************************
		// Method:    ��ȡһ�� INT64 ����
		//************************************
		INT64 ReadInt64();

		//************************************
		// Method:    ��ȡһ�� UINT64 ����
		//************************************
		UINT64 ReadUInt64();

		//************************************
		// Method:    ��ȡһ�� float ����
		//************************************
		float ReadFloat();

		//************************************
		// Method:    ��ȡһ�� double ����
		//************************************
		double ReadDouble();

		//************************************
		// Method:    ��ȡ GB2312 �ַ���
		// Parameter: int len:	��ȡ�ֽڳ���
		//************************************
		string ReadGB2312Str(int len);

		//************************************
		// Method:    ��ȡ GB2312 �ַ���
		// Parameter: int prefixLen = 4:	˵���ַ����ֽڳ��ȵ�ǰ׺������ռ�ֽڳ���, ȡֵ��Χ: 1-4
		// Parameter: bool hasEndChar:	�Ƿ����������
		// Parameter: bool isPrefixContainEndChar:	ǰ׺��ֵ�Ƿ����������
		//************************************
		string ReadGB2312Str1(int prefixLen = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);

		//************************************
		// Method:    ��ȡ UTF16 �ַ���
		// Parameter: int len:	��ȡ�ֽڳ���
		//************************************
		wstring ReadUTF16Str(int len);

		//************************************
		// Method:    ��ȡ UTF16 �ַ���
		// Parameter: int prefixLen = 4:	˵���ַ����ֽڳ��ȵ�ǰ׺������ռ�ֽڳ���, ȡֵ��Χ: 1-4
		// Parameter: bool hasEndChar:	�Ƿ����������
		// Parameter: bool isPrefixContainEndChar:	ǰ׺��ֵ�Ƿ����������
		//************************************
		wstring ReadUTF16Str1(int prefixLen = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);

		//************************************
		// Method:    ��ȡ UT8 �ַ���, �Զ�ת���� GB2312 �ַ��� 
		// Parameter: int len:	��ȡ�ֽڳ���
		//************************************
		string ReadUTF8Str(int len);

		//************************************
		// Method:    ��ȡ UT8 �ַ���, �Զ�ת���� GB2312 �ַ��� 
		// Parameter: int prefixLen = 4:	˵���ַ����ֽڳ��ȵ�ǰ׺������ռ�ֽڳ���, ȡֵ��Χ: 1-4
		// Parameter: bool hasEndChar:	�Ƿ����������
		// Parameter: bool isPrefixContainEndChar:	ǰ׺��ֵ�Ƿ����������
		//************************************
		string ReadUTF8Str1(int prefixLen = 4, bool hasEndChar = true, bool isPrefixContainEndChar = true);
	};
}