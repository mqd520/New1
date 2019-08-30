#include "stdafx.h"
#include "GameCenterSection.h"
#include "Def.h"

#include "com/IniHelper.h"
using namespace com;

#define SectionName_GameCenter		("GameCenter")		// GameCenter section name
#define SectionKeyName_IP			("ip")				// key name: ip
#define SectionKeyName_Port			("port")			// key name: port


GameCenterSection::GameCenterSection(string strFilePath) :
strIp(IniHelper::ReadString(SectionName_GameCenter, SectionKeyName_IP, CS_Config_GameCenter_IP, strFilePath)),
nPort(IniHelper::ReadInt(SectionName_GameCenter, SectionKeyName_Port, CS_Config_GameCenter_Port, strFilePath))
{

}

GameCenterSection::~GameCenterSection()
{

}