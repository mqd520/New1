#pragma once

#include "DbService.h"
#include "ApplyGameRoundResult.h"

namespace db
{
	// Apply game round
	class ApplyGameRoundSrv : public DbService
	{
	public:
		//************************************
		// Method:    constructor
		//************************************
		ApplyGameRoundSrv();

		//************************************
		// Method:    constructor
		// Parameter: string addr: http request addr
		//************************************
		ApplyGameRoundSrv(string addr);

	protected:
		//************************************
		// Method:    parse db result
		// Parameter: HttpResponseData & data
		//************************************
		DbResult* ParseDbResult(HttpResponseData& data) override;
	};
}