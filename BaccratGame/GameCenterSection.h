#pragma once

#include <string>
using namespace std;

// Game Center section
class GameCenterSection
{
public:
	GameCenterSection(string strFilePath);
	~GameCenterSection();

public:
	const string strIp;		// ip
	const int nPort;		// port
};