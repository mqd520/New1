#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"

namespace db
{
	// PlayerLoginResult Parameter
	class PlayerLoginResultPara : public DbOutputParameter
	{
	public:
		int nA;				// nA
		string str1;		// str1
	};

	// PlayerLoginResult
	class PlayerLoginResult : public DbResult
	{
	public:
		string strAccount;		// account
	};
}