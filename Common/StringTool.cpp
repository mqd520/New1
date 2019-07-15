#include "stdafx.h"
#include "Include/com/StringTool.h"

namespace com
{
	StringTool::StringTool()
	{

	}

	void StringTool::Split(const string& strSrc, vector<string>& vec, const string& strFind)
	{
		string::size_type pos1, pos2;
		pos2 = strSrc.find(strFind);
		pos1 = 0;

		while (string::npos != pos2)
		{
			vec.push_back(strSrc.substr(pos1, pos2 - pos1));

			pos1 = pos2 + strFind.size();
			pos2 = strSrc.find(strFind, pos1);
		}

		if (pos1 != strSrc.length())
		{
			vec.push_back(strSrc.substr(pos1));
		}
	}
}