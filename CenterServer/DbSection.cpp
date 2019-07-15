#include "stdafx.h"
#include "DbSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_Db				("Db")				// Db section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port


DbSection::DbSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_Db, SectionKeyName_IP, CS_Config_Db_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_Db, SectionKeyName_Port, CS_Config_Db_Port, strFilePath))
{

}

DbSection::~DbSection()
{

}