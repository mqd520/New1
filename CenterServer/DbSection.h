#pragma once

#include <string>
using namespace std;

// db section
class DbSection
{
public:
	DbSection(string strFilePath);
	~DbSection();

public:
	const string strIp;		// ip
	const int nPort;		// port
};