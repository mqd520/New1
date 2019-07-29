#pragma once

namespace gameDef
{
	// Game type
	enum class EGameType
	{
		Baccrat = 100,				// baccrat
		DragonTrigger = 104,		// dragon trigger
		Sico = 105					// Sico
	};

	// Game main status
	enum class EGameMainStatus : int
	{
		Stop,			// stop
		Running,		// running
		Paused,			// paused

		None			// None
	};

	// Game status
	enum class EGameStatus
	{
		Stop,						// stop

		Prepare,					// prepare to start new round
		Bet,						// bet
		StopBet,					// stop bet
		Send,						// send card
		Publish,					// publish game result
		Settle,						// settle

		None,						// None(Invalid)
	};
}