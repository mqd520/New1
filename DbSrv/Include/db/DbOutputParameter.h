#pragma once

#include <string>
using namespace std;


namespace db
{
	// db iutput patameter
	class DbOutputParameter
	{
	public:
		int nCount;		// parameter count

	public:
		DbOutputParameter(int count = 0) : nCount(count){}
	};




	// Player	---------------------------------------------------------------------------------------

	// PlayerLoginResult Parameter
	class PlayerLoginResultPara : public DbOutputParameter
	{
	public:
		int nA;				// nA
		string str1;		// str1
	};

	// Player	---------------------------------------------------------------------------------------
}