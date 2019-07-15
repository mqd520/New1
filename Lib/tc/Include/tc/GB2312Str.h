#pragma once

#include <string>

using namespace std;

namespace tc
{
	/************************************************************************/
	/* GB2312�ַ�������                                                                     */
	/************************************************************************/
	class GB2312Str
	{
	public:
		GB2312Str();
		~GB2312Str();

		//************************************
		// Method:    �ӻ������ж�ȡ GB2312 �ַ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: int len:		����������
		//************************************
		static string FromBuf(BYTE* pBuf, int len);

		//************************************
		// Method:    �� UTF8 �������ж�ȡ GB2312 �ַ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: int len:		����������
		//************************************
		static string FromUTF8Buf(BYTE* pBuf, int len);

		//************************************
		// Method:    �� UTF16 �ַ����ж�ȡ GB2312 �ַ���
		// Parameter: str:	UTF16�ַ���
		//************************************
		static string FromUTF16(wstring str);

		//************************************
		// Method:    ��ȡ�ַ����ֽڳ���(������������)
		//************************************
		static int GetByteCount(string str);

		//************************************
		// Method:    д�뵽��������
		// Return:	  д�뻺�����ĳ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: hasEndChar:	�Ƿ�д�������
		//************************************
		static int ToBuf(string str, BYTE* pBuf, bool hasEndChar = false);

		//************************************
		// Method:    д�뵽 UTF8 ��������
		// Return:	  д�뻺�����ĳ���
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: hasEndChar:	�Ƿ�д�������
		//************************************
		static int ToUTF8Buf(string str, BYTE* pBuf, bool hasEndChar = false);

	private:

	};
}