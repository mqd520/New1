#pragma once

#include <string>

using namespace std;

namespace tc
{
	//************************************
	// Method:    ���ֽ��ַ���תUTF8�ַ���
	// FullName:  Common::MultiByteToUTF8
	// Access:    public 
	// Returns:   std::wstring
	// Qualifier:
	// Parameter: const char * str
	//************************************
	wstring MultiByteToUTF8(const char* str);

	//************************************
	// Method:    UTF8�ַ���ת���ֽ��ַ���
	// FullName:  Common::UTF8ToMultiByte
	// Access:    public 
	// Returns:   std::string
	// Qualifier:
	// Parameter: const wchar_t * str
	//************************************
	string UTF8ToMultiByte(const wchar_t* str);

	//************************************
	// Method:    ��ȡ���ֽ��ַ����ֽ���
	// FullName:  NetTool::GetStrByteCount
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: TCHAR * str
	//************************************
	int GetAStrByteCount(char* str);

	//************************************
	// Method:    ��ȡ���ֽ��ַ����ֽ���
	// FullName:  NetTool::GetStrByteCount
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: TCHAR * str
	//************************************
	int GetWStrByteCount(wchar_t* str);

	//************************************
	// Method:    ��ȡ�ַ����ֽ���
	// FullName:  Common::GetStrByteCount
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: TCHAR * str
	//************************************
	int GetStrByteCount(TCHAR* str);

	//************************************
	// Method:    ��ȡָ��ֵ�ĵ�һ���ֽ�
	// FullName:  ProtocolTool::GetFstByteFromInt
	// Access:    public 
	// Returns:   BYTE
	// Qualifier:
	// Parameter: int n
	//************************************
	BYTE GetFstByteFromInt(int n);

	//************************************
	// Method:    ��ȡָ��ֵ�ĵڶ����ֽ�
	// FullName:  ProtocolTool::GetSecByteFromInt
	// Access:    public 
	// Returns:   BYTE
	// Qualifier:
	// Parameter: int n
	//************************************
	BYTE GetSecByteFromInt(int n);

	//************************************
	// Method:    ��ȡָ��ֵ�ĵ������ֽ�
	// FullName:  ProtocolTool::GetTrdByteFromInt
	// Access:    public 
	// Returns:   BYTE
	// Qualifier:
	// Parameter: int n
	//************************************
	BYTE GetTrdByteFromInt(int n);

	//************************************
	// Method:    ��ȡָ��ֵ�ĵ��ĸ��ֽ�
	// FullName:  ProtocolTool::GetFouthByteFromInt
	// Access:    public 
	// Returns:   BYTE
	// Qualifier:
	// Parameter: int n
	//************************************
	BYTE GetFouthByteFromInt(int n);

	//************************************
	// Method:    �ϲ��ֽڵ�int
	// FullName:  ProtocolTool::MergeByte
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: BYTE fouth
	// Parameter: BYTE trd
	// Parameter: BYTE sec
	// Parameter: BYTE fst
	//************************************
	int MergeByte(BYTE fouth = 0, BYTE trd = 0, BYTE sec = 0, BYTE fst = 0);

	//************************************
	// Method:    �Ӷ��ֽ��ַ����������л�ȡ�ַ�����
	// FullName:  ProtocolTool::GetLenFromMultiByteBuf
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: ���ֽ��ַ���������
	// Parameter: ��ʼλ��
	// Parameter: ����λ��
	//************************************
	int GetLenFromMultiByteBuf(BYTE* buf, int start, int end);

	//************************************
	// Method:    д��int�������ݵ�������
	// FullName:  NetworkCommunication::ReadValue
	// Access:    public 
	// Returns:   ������
	// Qualifier:
	// Parameter: ֵ
	// Parameter: �Ƿ�ʹ��С�ֽ���(�����ֽ���)
	//************************************
	BYTE* WriteIntToBuf(int val, bool bLittleEndian = true);

	//************************************
	// Method:    д��short�������ݵ�������
	// FullName:  NetworkCommunication::ReadValue
	// Access:    public 
	// Returns:   ������
	// Qualifier:
	// Parameter: ֵ
	// Parameter: �Ƿ�ʹ��С�ֽ���(�����ֽ���)
	//************************************
	BYTE* WriteShortToBuf(short val, bool bLittleEndian = true);

	//************************************
	// Method:    ���ֽ������ж�ȡ���ֽ��ַ���
	// FullName:  NetTool::ReadMultiByteStr
	// Access:    public 
	// Returns:   std::string
	// Qualifier:
	// Parameter: �ֽ�����
	// Parameter: �ֽ����鳤��
	//************************************
	string ReadMultiByteStr(BYTE buf[], int len);

	//************************************
	// Method:    ���ֽ������ж�ȡUTF8�ַ���
	// FullName:  NetTool::ReadUTF8Str
	// Access:    public 
	// Returns:   std::wstring
	// Qualifier:
	// Parameter: �ֽ�����
	// Parameter: �ֽ����鳤��
	//************************************
	wstring ReadUTF8ByteStr(BYTE buf[], int len);

	//************************************
	// Method:    д����ֽ��ַ������ֽ�����
	// FullName:  NetTool::WriteMultiByteStr
	// Access:    public 
	// Returns:   BYTE*
	// Qualifier:
	// Parameter: ���ֽ��ַ���
	// Parameter: �ֽ����鳤��(���)
	//************************************
	BYTE* WriteMultiByteStr(char* str, int* size);

	//************************************
	// Method:    д��UTF8�ַ������ֽ�����
	// FullName:  NetTool::WriteUTF8Str
	// Access:    public 
	// Returns:   BYTE*
	// Qualifier:
	// Parameter: UTF8�ַ���
	// Parameter: �ֽ����鳤��(���)
	//************************************
	BYTE* WriteUTF8Str(wchar_t* str, int* size);
}