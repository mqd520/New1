#pragma once

#include "DbOutputParameter.h"

#include <string>
using namespace std;

namespace db
{
	// DbResult
	class DbResult
	{
	public:
		bool bSuccess;				// whether success
		DbOutputParameter* pParam;	// para pointer

	public:
		DbResult(bool success = false) :
			bSuccess(success), pParam(NULL)
		{

		}

		virtual ~DbResult()
		{
			if (pParam)
			{
				delete pParam;
				pParam = NULL;
			}
		}
	};




	// Player	---------------------------------------------------------------------------------------

	// PlayerLoginResult
	class PlayerLoginResult : public DbResult
	{
	public:
		string strAccount;		// account
	};

	// Player	---------------------------------------------------------------------------------------
}