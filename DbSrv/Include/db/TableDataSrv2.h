#pragma once

#include "DbService.h"
#include "TableDataResult2.h"

namespace db
{
	// Load table data
	class TableDataSrv2 : public DbService
	{
	public:
		//************************************
		// Method:    constructor
		//************************************
		TableDataSrv2();

		//************************************
		// Method:    constructor
		// Parameter: string addr: http request addr
		//************************************
		TableDataSrv2(string addr);

	protected:
		//************************************
		// Method:    parse db result
		// Parameter: HttpResponseData & data
		//************************************
		DbResult* ParseDbResult(HttpResponseData& data) override;
	};
}