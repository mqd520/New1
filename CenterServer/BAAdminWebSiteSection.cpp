#include "stdafx.h"
#include "BAAdminWebSiteSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_BA				("Ba")				// backstage admin website service section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port
#define SectionKeyName_AllowIps		("allowIps")		// key name: allowIps


BAAdminWebSiteSection::BAAdminWebSiteSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_BA, SectionKeyName_IP, CS_Config_BA_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_BA, SectionKeyName_Port, CS_Config_BA_Port, strFilePath)),
strAllowIps(IniHelper::ReadString(SectionName_BA, SectionKeyName_AllowIps, "127.0.0.1", strFilePath))
{

}

BAAdminWebSiteSection::~BAAdminWebSiteSection()
{

}