#include "stdafx.h"
#include "Include/game/ApplyGameRoundCplEvt.h"

namespace game
{
	ApplyGameRoundCplEvt::ApplyGameRoundCplEvt(bool bSuccess) :
		GameEvt(EGameEvtType::ApplyGameRoundCpl),
		bSuccess(bSuccess)
	{

	}

	bool ApplyGameRoundCplEvt::IsSuccessed() const
	{
		return bSuccess;
	}
}