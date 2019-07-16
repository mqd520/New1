#pragma once

#include <string>
using namespace std;

// SendCard section
class SendCardSection
{
public:
	SendCardSection(string strFilePath);
	~SendCardSection();

public:
	const string strIp;		// ip
	const int nPort;		// port
};