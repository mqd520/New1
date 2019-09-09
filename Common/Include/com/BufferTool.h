#pragma once

#include <minwindef.h>
#include <string>
using namespace std;


namespace com
{
	// Buffer Tool
	class BufferTool final
	{
	private:
		BufferTool();

	public:
		//************************************
		// Method:    Join buf to be string
		// Parameter: BYTE * pBuf
		// Parameter: int len
		// Parameter: char * split
		// Parameter: char * format
		//************************************
		static string Join(BYTE* pBuf, int len, char* split = ", ", char* format = "%d");

		//************************************
		// Method:    Reverse
		// Parameter: BYTE * buf
		// Parameter: int len
		//************************************
		static void Reverse(BYTE* pBuf, int len);
	};
}