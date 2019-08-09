#include "stdafx.h"
#include "GS_Prepare.h"

GS_Prepare::GS_Prepare(int nDurationTime) :
GameStatus(EGameStatus::Prepare, nDurationTime)
{

}

EGameMainStatus GS_Prepare::GetCurGameMainStatus()
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Prepare::GetNextStatus()
{
	return EGameStatus::Bet;
}

void GS_Prepare::Enter()
{
	StartCountdown();
}

bool GS_Prepare::IsCompleted()
{
	return IsCountdownDone();
}