#include "stdafx.h"
#include "DbServiceSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;


#define SectionName_Db				("Db")				// Db service section name
#define SectionKeyName_Addr			("addr")			// key name: addr


DbServiceSection::DbServiceSection(string strFilePath) :
strDbSrvAddr(IniHelper::ReadString(SectionName_Db, SectionKeyName_Addr, CS_Config_Db_Addr, strFilePath))
{

}

DbServiceSection::~DbServiceSection()
{

}