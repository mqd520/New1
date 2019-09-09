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
		// Method:    ip 点分制转换成int
		// Parameter: string ip
		//************************************
		//static int ConvertIP(string ip);

		//************************************
		// Method:    ip int 转换成 点分制
		// Parameter: int ip
		//************************************
		//static string ConvertIP(int ip);

		//************************************
		// Method:    获取当前可执行程序的目录
		//************************************
		static string GetCurrentDir();

		//************************************
		// Method:    Create a guid string
		//************************************
		static string CreateGuid();
	};
}