#pragma once

#include <string>
using namespace std;

// plaza section
class PlazaSection
{
public:
	PlazaSection(string strFilePath);
	~PlazaSection();

public:
	const string strIp;		// ip
	const int nPort;		// port
};