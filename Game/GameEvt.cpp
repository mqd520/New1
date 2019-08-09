#include "stdafx.h"
#include "Include/game/GameEvt.h"

namespace game
{
	GameEvt::GameEvt(EGameEvtType type) :
		type(type)
	{

	}

	GameEvt::~GameEvt()
	{

	}

	EGameEvtType GameEvt::GetEvtType() const
	{
		return type;
	}
}