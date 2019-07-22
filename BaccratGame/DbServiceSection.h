#pragma once

#include <string>
using namespace std;

// Db service section
class DbServiceSection
{
public:
	DbServiceSection(string strFilePath);
	~DbServiceSection();

public:
	const string strDbSrvAddr;			// Db service addr
};