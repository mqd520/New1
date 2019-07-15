#pragma once
#include <minwindef.h>

namespace pck
{
	// ������
	class EncryptHelper final
	{
	private:
		EncryptHelper();

	public:
		//************************************
		// Method:    ����������
		// Parameter: char * pBuf
		// Parameter: int len
		//************************************
		static BYTE Encrypt(BYTE* pBuf, int len);

		//************************************
		// Method:    ����������
		// Parameter: char * pBuf
		// Parameter: int len
		// Parameter: BYTE code
		//************************************
		static bool Decrypt(BYTE* pBuf, int len, BYTE code);
	};
}