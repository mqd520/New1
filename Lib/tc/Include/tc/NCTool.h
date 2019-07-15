#pragma once
#include <string>

using namespace std;

namespace tc
{
	// �ֽ���ö��ֵ����
	enum EByteOrder
	{
		litte = 1,	// С���ֽ���
		big = 2		// ����ֽ���
	};

	class NCTool
	{
	public:
		NCTool();
		~NCTool();

	public:
		//************************************
		// Method:    ��ȡ��ǰ�����ֽ���
		// Access:    public static 
		// Returns:   EByteOrder
		//************************************
		static EByteOrder GetHostByteOrder();

		//************************************
		// Method:    ��ת������
		// Parameter: BYTE * pBuf:	������ָ��
		// Parameter: int len:		����������
		//************************************
		static void ReverseBuf(BYTE* pBuf, int len);

		//************************************
		// Method:    ����һ�������
		// Parameter: min: ��Сֵ
		// Parameter: max: ���ֵ
		//************************************
		static int CreateRand(unsigned int min = 0, unsigned int max = 0);

	private:

	};
}

