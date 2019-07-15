#pragma once

#include <string>
using namespace std;

// Table section
class TableSection
{
public:
	TableSection(string strFilePath);
	~TableSection();

public:
	const string strIp;		// ip
	const int nPort;		// port
};