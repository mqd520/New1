#pragma once

#include <string>
using namespace std;

namespace db
{
	namespace tbl
	{
		// UserInfoTbl
		struct tagUserInfoTbl
		{
			int			nUserId;				// UserId
			string		strAccount;				// account
			string		strNickname;			// nickname
			string		strPwd;					// pwd
			double		dblBalance;				// balance
		}UserInfoTbl;
	}
}