#pragma once

#include <string>
#include <vector>
using namespace std;

namespace com
{
	// string tool
	class StringTool final
	{
	private:
		StringTool();

	public:
		static void Split(const string& strSrc, vector<string>& vec, const string& strFind);
	};
}