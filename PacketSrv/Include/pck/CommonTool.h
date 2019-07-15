#pragma once
#include "Def.h"
#include <string>
using namespace std;

namespace pck
{
	// pck srv tool
	class CommonTool final
	{
	private:
		CommonTool();

	public:
		//************************************
		// Method:    ����һ��guid
		//************************************
		static string CreateGuid();

		//************************************
		// Method:    ��ȡ����������
		// Parameter: EServerType type
		//************************************
		static string GetServerName(EServerType type);
	};
}