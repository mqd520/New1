#pragma once

#include "DbService.h"
#include "TableDataResult.h"

namespace db
{
	// Load table data
	class TableDataSrv : public DbService
	{
	public:
		//************************************
		// Method:    constructor
		//************************************
		TableDataSrv();

		//************************************
		// Method:    constructor
		// Parameter: string addr: http request addr
		//************************************
		TableDataSrv(string addr);

	protected:
		//************************************
		// Method:    parse db result
		// Parameter: HttpResponseData & data
		//************************************
		virtual DbResult* ParseDbResult(HttpResponseData& data) override;
	};
}