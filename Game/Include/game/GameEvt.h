#pragma once

#include "GameDef.h"

namespace game
{
	// GameEvt
	class GameEvt
	{
	public:
		GameEvt(EGameEvtType type);

		virtual ~GameEvt();

	private:
		EGameEvtType type;		// evt type

	public:
		//************************************
		// Method:    Get evt type
		//************************************
		EGameEvtType GetEvtType() const;

		//************************************
		// Method:    Get obj
		//************************************
		void* GetObj() const;
	};
}