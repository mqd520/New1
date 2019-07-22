#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"

namespace db
{
	// TableDataResult
	class TableDataResult : public DbResult
	{
	public:
		int nId;				// table Id
		string strTableName;	// table name
		int nGameType;			// game type
		int nType;				// type
		int nStatus;			// table status
		int nGroupCount;		// group count
		int nSeatCount;			// seat count
		int nTypeId;			// type id
	};
}