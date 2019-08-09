#pragma once

#include "GameEvt.h"

namespace game
{
	// Apply Game Round Complete Evt
	class ApplyGameRoundCplEvt : public GameEvt
	{
	public:
		ApplyGameRoundCplEvt(bool bSuccess);

	private:
		bool bSuccess;		// whether success

	public:
		//************************************
		// Method:    Is success
		//************************************
		bool IsSuccessed() const;
	};
}