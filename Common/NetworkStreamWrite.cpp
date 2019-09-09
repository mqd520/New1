#include "stdafx.h"
#include "Include/com/NetworkStreamWrite.h"

#include "Include/com/StreamTool.h"
#include "Include/com/BufferTool.h"
#include "Include/com/StringTool.h"


namespace com
{
	NetworkStreamWrite::NetworkStreamWrite(BYTE* buf, int len, EEndian bo /*= EByteOrder::big*/) :
		NetworkStream(buf, len, bo)
	{

	}

	int NetworkStreamWrite::WriteData(void* pDest, int len)
	{
		int result = 0;

		if (len <= AvaliableByteCount())
		{
			memcpy(pBuf + nDataIndex, pDest, len);

			if (len > 1 && bo != StreamTool::GetLocalHostEndian())
			{
				BufferTool::Reverse(pBuf + nDataIndex, len);
			}

			nDataIndex += len;

			result = len;
		}

		return result;
	}

	int NetworkStreamWrite::WriteStrPrefixVal(EStringPrefixByteLen len, int val)
	{
		int result = 0;

		if (len == EStringPrefixByteLen::Byte)
		{
			BYTE val1 = (BYTE)val;
			result = WriteByte(val1);
		}
		else if (len == EStringPrefixByteLen::Int16)
		{
			INT16 val1 = (INT16)val;
			result = WriteInt16(val1);
		}
		else if (len == EStringPrefixByteLen::Int32)
		{
			INT32 val1 = (INT32)val;
			result = WriteInt32(val1);
		}

		return result;
	}

	int NetworkStreamWrite::WriteBuf(BYTE* buf, int len)
	{
		int result = 0;

		if (len > 0 && buf && len <= AvaliableByteCount())
		{
			memcpy(pBuf + nDataIndex, buf, len);

			nDataIndex += len;

			result = len;
		}

		return result;
	}

	int NetworkStreamWrite::WriteByte(BYTE& val)
	{
		return WriteData(&val, sizeof(BYTE));
	}

	int NetworkStreamWrite::WriteShort(SHORT& val)
	{
		return WriteData(&val, sizeof(SHORT));
	}

	int NetworkStreamWrite::WriteUShort(USHORT& val)
	{
		return WriteData(&val, sizeof(USHORT));
	}

	int NetworkStreamWrite::WriteInt16(INT16& val)
	{
		return WriteData(&val, sizeof(INT16));
	}

	int NetworkStreamWrite::WriteUInt16(UINT16& val)
	{
		return WriteData(&val, sizeof(UINT16));
	}

	int NetworkStreamWrite::WriteInt32(INT32& val)
	{
		return WriteData(&val, sizeof(INT32));
	}

	int NetworkStreamWrite::WriteUInt32(UINT32& val)
	{
		return WriteData(&val, sizeof(UINT32));
	}

	int NetworkStreamWrite::WriteInt64(INT64& val)
	{
		return WriteData(&val, sizeof(INT64));
	}

	int NetworkStreamWrite::WriteUInt64(UINT64& val)
	{
		return WriteData(&val, sizeof(UINT64));
	}

	int NetworkStreamWrite::WriteFloat(FLOAT& val)
	{
		return WriteData(&val, sizeof(FLOAT));
	}

	int NetworkStreamWrite::WriteDouble(double& val)
	{
		return WriteData(&val, sizeof(double));
	}

	int NetworkStreamWrite::WriteGB2312Str(string str, bool hasPrefix /*= true*/, EStringPrefixByteLen prefixLen /*= EStringPrefixByteLen::Int32*/,
		bool hasEndChar /*= true*/, bool isPrefixContainEndChar /*= true*/)
	{
		int result = 0;

		int len1 = 0;		// ǰ׺��ֵ
		int len2 = 0;		// �ַ������ֽڳ���, ���������������ֽڳ���
		int len3 = 0;		// �ַ������ֽڳ���, �������������ֽڳ���(�������д�������), ������ǰ׺���ֽڳ���
		int len4 = 0;		// ��Ҫд����ֽ��ܳ���

		StringTool::GetGB2312StrLen((char*)str.c_str(), nullptr, &len2);
		len3 = hasEndChar ? len2 + 1 : len2;

		if (hasEndChar && isPrefixContainEndChar)
		{
			len1 = len3;	// ����д�������, ����ǰ׺��Ҫ�������������ֽڳ���
		}
		else
		{
			len1 = len2;	// ֻ��ʾ�ַ����ֽڳ���, ������������
		}

		if (hasPrefix)
		{
			len4 = (int)prefixLen + len3;	// ǰ׺�ֽڳ��� + �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}
		else
		{
			len4 = len3;					// �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}

		if (len4 <= AvaliableByteCount())
		{
			if (hasPrefix)
			{
				result = WriteStrPrefixVal(prefixLen, len1);		// д��ǰ׺ֵ
				if (result == 0)
				{
					return result;
				}
			}

			memcpy(pBuf + nDataIndex, str.c_str(), len2);

			if (hasEndChar)
			{
				pBuf[nDataIndex + len2 + 1] = 0;
			}

			nDataIndex += len3;

			result = len4;
		}

		return result;
	}

	int NetworkStreamWrite::WriteUTF16Str(wstring str, bool hasPrefix /*= true*/, EStringPrefixByteLen prefixLen /*= EStringPrefixByteLen::Int32*/,
		bool hasEndChar /*= true*/, bool isPrefixContainEndChar /*= true*/)
	{
		int result = 0;

		int len1 = 0;		// ǰ׺��ֵ
		int len2 = 0;		// �ַ������ֽڳ���, ���������������ֽڳ���
		int len3 = 0;		// �ַ������ֽڳ���, �������������ֽڳ���(�������д�������), ������ǰ׺���ֽڳ���
		int len4 = 0;		// ��Ҫд����ֽ��ܳ���

		StringTool::GetUTF16StrLen((wchar_t*)str.c_str(), nullptr, &len2);
		len3 = hasEndChar ? len2 + 2 : len2;

		if (hasEndChar && isPrefixContainEndChar)
		{
			len1 = len3;	// ����д�������, ����ǰ׺��Ҫ�������������ֽڳ���
		}
		else
		{
			len1 = len2;	// ֻ��ʾ�ַ����ֽڳ���, ������������
		}

		if (hasPrefix)
		{
			len4 = (int)prefixLen + len3;	// ǰ׺�ֽڳ��� + �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}
		else
		{
			len4 = len3;					// �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}

		if (len4 <= AvaliableByteCount())
		{
			if (hasPrefix)
			{
				result = WriteStrPrefixVal(prefixLen, len1);		// д��ǰ׺ֵ
				if (result == 0)
				{
					return result;
				}
			}

			memcpy(pBuf + nDataIndex, str.c_str(), len2);

			if (bo != StreamTool::GetLocalHostEndian())
			{
				for (int i = 0; i < len2; i += 2)
				{
					BYTE tmp = pBuf[nDataIndex + i];
					pBuf[nDataIndex + i] = pBuf[nDataIndex + i + 1];
					pBuf[nDataIndex + i + 1] = tmp;
				}
			}

			if (hasEndChar)
			{
				pBuf[nDataIndex + len2 + 1] = 0;
				pBuf[nDataIndex + len2 + 2] = 0;
			}

			nDataIndex += len3;

			result = len4;
		}

		return result;
	}

	int NetworkStreamWrite::WriteUTF8Str(string str, bool hasPrefix /*= true*/, EStringPrefixByteLen prefixLen /*= EStringPrefixByteLen::Int32*/,
		bool hasEndChar /*= true*/, bool isPrefixContainEndChar /*= true*/)
	{
		int result = 0;

		int len1 = 0;		// ǰ׺��ֵ
		int len2 = 0;		// �ַ������ֽڳ���, ���������������ֽڳ���
		int len3 = 0;		// �ַ������ֽڳ���, �������������ֽڳ���(�������д�������), ������ǰ׺���ֽڳ���
		int len4 = 0;		// ��Ҫд����ֽ��ܳ���

		StringTool::GetUTF8StrLen((char*)str.c_str(), nullptr, &len2);
		len3 = hasEndChar ? len2 + 1 : len2;

		if (hasEndChar && isPrefixContainEndChar)
		{
			len1 = len3;	// ����д�������, ����ǰ׺��Ҫ�������������ֽڳ���
		}
		else
		{
			len1 = len2;	// ֻ��ʾ�ַ����ֽڳ���, ������������
		}

		if (hasPrefix)
		{
			len4 = (int)prefixLen + len3;	// ǰ׺�ֽڳ��� + �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}
		else
		{
			len4 = len3;					// �ַ���(�������ܴ��ڵĽ�����)�ֽڳ���
		}

		if (len4 <= AvaliableByteCount())
		{
			if (hasPrefix)
			{
				result = WriteStrPrefixVal(prefixLen, len1);		// д��ǰ׺ֵ
				if (result == 0)
				{
					return result;
				}
			}

			memcpy(pBuf + nDataIndex, str.c_str(), len2);

			if (hasEndChar)
			{
				pBuf[nDataIndex + len2 + 1] = 0;
			}

			nDataIndex += len3;

			result = len4;
		}

		return result;
	}
}