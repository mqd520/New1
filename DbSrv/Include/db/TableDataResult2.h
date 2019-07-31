#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"
#include "TableData.h"

namespace db
{
	// TableDataResult
	class TableDataResult2 : public DbResult
	{
	public:
		vector<TableData> vecTables;		// table list
		vector<int> vecUpdatedTableIds;		// updated table Id list
	};
}