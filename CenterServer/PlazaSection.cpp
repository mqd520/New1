#include "stdafx.h"
#include "PlazaSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_Plaza			("Plaza")			// plaza section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port


PlazaSection::PlazaSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_Plaza, SectionKeyName_IP, CS_Config_Plaza_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_Plaza, SectionKeyName_Port, CS_Config_Plaza_Port, strFilePath))
{

}

PlazaSection::~PlazaSection()
{

}