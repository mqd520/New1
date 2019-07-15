#include "stdafx.h"
#include "SendCardSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_SendCard		("SendCard")		// SendCard section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port


SendCardSection::SendCardSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_SendCard, SectionKeyName_IP, CS_Config_SendCard_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_SendCard, SectionKeyName_Port, CS_Config_SendCard_Port, strFilePath))
{

}

SendCardSection::~SendCardSection()
{

}