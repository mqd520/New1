#pragma once

#include "DbService.h"
#include "PlayerLoginResult.h"

namespace db
{
	// Player Login
	class PlayerLoginSrv : public DbService
	{
	public:
		//************************************
		// Method:    constructor
		//************************************
		PlayerLoginSrv();

		//************************************
		// Method:    constructor
		// Parameter: string addr: http request addr
		//************************************
		PlayerLoginSrv(string addr);

	protected:
		//************************************
		// Method:    parse db result
		// Parameter: HttpResponseData & data
		//************************************
		virtual DbResult* ParseDbResult(HttpResponseData& data) override;
	};
}