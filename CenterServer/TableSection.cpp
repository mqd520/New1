#include "stdafx.h"
#include "TableSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_Table			("Table")			// Table section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port


TableSection::TableSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_Table, SectionKeyName_IP, CS_Config_Table_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_Table, SectionKeyName_Port, CS_Config_Table_Port, strFilePath))
{

}

TableSection::~TableSection()
{

}