#pragma once

#include <string>
using namespace std;

// backstage admin website service section
class BAAdminWebSiteSection
{
public:
	BAAdminWebSiteSection(string strFilePath);
	~BAAdminWebSiteSection();

public:
	const string strIp;			// ip
	const int nPort;			// port
	const string strAllowIps;	// allow ip list
};