#include "stdafx.h"
#include "GS_Bet.h"

GS_Bet::GS_Bet(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::Bet, isAutoEnterNext, nDurationTime)
{
	SetReadyState();
}

EGameMainStatus GS_Bet::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Bet::GetNextStatus() const
{
	return EGameStatus::StopBet;
}