#include "stdafx.h"
#include "Include/com/BufferTool.h"

namespace com
{
	BufferTool::BufferTool()
	{

	}

	string BufferTool::Join(BYTE* pBuf, int len, char* split /*= ", "*/, char* format /*= "%d"*/)
	{
		string result = "";

		for (int i = 0; i < len; i++)
		{
			string str = format;
			if (i < len - 1)
			{
				str += split;
			}

			char ch[30] = { 0 };
			sprintf_s(ch, str.c_str(), pBuf[i]);

			result += ch;
		}

		return result;
	}

	void BufferTool::Reverse(BYTE* pBuf, int len)
	{
		if (pBuf && len > 0)
		{
			for (int i = 0; i < len / 2; i++)
			{
				BYTE tmp = pBuf[len - 1 - i];
				pBuf[len - 1 - i] = pBuf[i];
				pBuf[i] = tmp;
			}
		}
	}
}