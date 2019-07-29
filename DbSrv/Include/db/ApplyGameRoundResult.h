#pragma once

#include "DbOutputParameter.h"
#include "DbResult.h"

namespace db
{
	// Apply Game Round Result
	class ApplyGameRoundResult : public DbResult
	{
	public:
		int nGameRoundId;		// game round Id
		string strGameRoundNo;	// game round no
		int nXue;				// xue
		int nPu;				// pu
		int nDuplicateId;		// duplicate Id
		bool bIsNewXue;			// whether new xue
	};
}