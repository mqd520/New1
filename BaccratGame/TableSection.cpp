#include "stdafx.h"
#include "TableSection.h"
#include "Def.h"

#include <string>

#include "com/IniHelper.h"
#include "com/StringTool.h"
using namespace com;


#define SectionName_Table		("Table")			// Table section name
#define SectionKeyName_Name		("list")			// key name: list

TableSection::TableSection(string strFilePath) :
strTableIds(IniHelper::ReadString(SectionName_Table, SectionKeyName_Name, "", strFilePath))
{
	if (!strTableIds.empty())
	{
		vector<string> vec;
		StringTool::Split(strTableIds, vec, ",");
		if (!vec.empty())
		{
			for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				string str = *it;
				StringTool::Trim(str);
				if (!str.empty())
				{
					int tableId = 0;
					int n = sscanf_s(str.c_str(), "%d", &tableId);
					if (n > 0)
					{
						vecTableIds.push_back(tableId);
					}
				}
			}
		}
	}
}

TableSection::~TableSection()
{

}