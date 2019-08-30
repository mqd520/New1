#include "stdafx.h"
#include "GS_Prepare.h"

GS_Prepare::GS_Prepare(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::Prepare, isAutoEnterNext, nDurationTime)
{

}

EGameMainStatus GS_Prepare::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Prepare::GetNextStatus() const
{
	return EGameStatus::Bet;
}