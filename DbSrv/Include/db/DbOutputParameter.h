#pragma once

#include <string>
using namespace std;


namespace db
{
	// db output patameter
	class DbOutputParameter
	{
	public:
		int nCount;		// parameter count

	public:
		DbOutputParameter(int count = 0) : nCount(count){}
	};
}