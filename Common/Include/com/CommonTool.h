#pragma once
#include <string>
using namespace std;

namespace com
{
	// common tool
	class CommonTool final
	{
	private:
		CommonTool();

	public:
		//************************************
		// Method:    ip �����ת����int
		// Parameter: string ip
		//************************************
		//static int ConvertIP(string ip);

		//************************************
		// Method:    ip int ת���� �����
		// Parameter: int ip
		//************************************
		//static string ConvertIP(int ip);

		//************************************
		// Method:    ��ȡ��ǰ��ִ�г����Ŀ¼
		//************************************
		static string GetCurrentDir();

		//************************************
		// Method:    Create a guid string
		//************************************
		static string CreateGuid();
	};
}