#pragma once

#include "NCTool.h"
#include <string>

using namespace std;

namespace tc
{
	/************************************************************************/
	/* UTF16�ַ�������                                                                     */
	/************************************************************************/
	class UTF16Str
	{
	public:
		UTF16Str();
		~UTF16Str();

		//************************************
		// Method:    �ӻ������ж�ȡ UTF16 �ַ���
		// Parameter: BYTE * pBuf:		������ָ��
		// Parameter: int len:			����������
		// Parameter: EByteOrder bo:	�������ֽ���, Ĭ��: ����ֽ���
		//************************************
		static wstring FromBuf(BYTE* pBuf, int len, EByteOrder bo = EByteOrder::big);

		//************************************
		// Method:    �� UTF8 ������ת���� UTF16 ������
		// Parameter: BYTE * pBuf1:		UTF8������ָ��
		// Parameter: int len1:			UTF8����������
		// Parameter: BYTE * pBuf2:		UTF16������ָ��
		// Parameter: int len2:			UTF16����������
		// Parameter: EByteOrder bo:	UTF16�������ֽ���, Ĭ��: ����ֽ���
		//************************************
		static void UTF8_2_UTF16(BYTE* pBuf1, int len1, BYTE* pBuf2, int* len2, EByteOrder bo = EByteOrder::big);

		//************************************
		// Method:    �� UTF16 ������ת���� UTF8 ������
		// Parameter: BYTE * pBuf1:		UTF16������ָ��
		// Parameter: int len1:			UTF16����������
		// Parameter: BYTE * pBuf2:		UTF8������ָ��
		// Parameter: int len2:			UTF8����������
		// Parameter: EByteOrder bo:	UTF16�������ֽ���, Ĭ��: ����ֽ���
		//************************************
		static void UTF16_2_UTF8(BYTE* pBuf1, int len1, BYTE* pBuf2, int* len2, EByteOrder bo = EByteOrder::big);

		//************************************
		// Method:    �� UTF8 �������ж�ȡ UTF16 �ַ���
		// Parameter: BYTE * pBuf:		������ָ��
		// Parameter: int len:			����������
		//************************************
		static wstring FromUTF8Buf(BYTE* pBuf, int len);

		//************************************
		// Method:    �� GB2312 �ַ����ж�ȡ UTF16 �ַ���
		// Parameter: str:	GB2312�ַ���
		//************************************
		static wstring FromGB2312(string str);

		//************************************
		// Method:    ��ȡ�ַ����ֽڳ���
		//************************************
		static int GetByteCount(wstring str);

		//************************************
		// Method:    д�뵽��������
		// Return:	  д�뻺�����ĳ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: hasEndChar:	�Ƿ�д�������
		// Parameter: EByteOrder bo:�������ֽ���, Ĭ��: ����ֽ���
		//************************************
		static int ToBuf(wstring str, BYTE* pBuf, EByteOrder bo = EByteOrder::big, bool hasEndChar = false);

		//************************************
		// Method:    д�뵽��������(UTF8)
		// Return:	  д�뻺�����ĳ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: hasEndChar:	�Ƿ�д�������
		//************************************
		static int ToUTF8Buf(wstring str, BYTE* pBuf, bool hasEndChar = false);

	private:

	};
}