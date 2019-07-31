#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"
#include "TableData.h"

namespace db
{
	// TableDataResult
	class TableDataResult : public DbResult
	{
	public:
		TableData	data;	// table data
	};
}