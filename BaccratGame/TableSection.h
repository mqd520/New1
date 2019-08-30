#pragma once

#include <vector>
using namespace std;


// Table section
class TableSection
{
public:
	TableSection(string strFilePath);
	~TableSection();

public:
	const string strTableIds;		// table Id list string
	vector<int> vecTableIds;		// table Id list
};