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

	// Game status
	enum class EGameStatus
	{
		Preparse,					// prepare to start new round
		CreateNewGameRound,			// creating new round
		Beting,						// bettig
		StopBet,					// stop bet
		Sending,					// send card
		CalcResult,					// calc game result
		Settle						// settle
	};
}