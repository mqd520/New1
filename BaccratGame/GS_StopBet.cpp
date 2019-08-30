#include "stdafx.h"
#include "GS_StopBet.h"

GS_StopBet::GS_StopBet(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::StopBet, isAutoEnterNext, nDurationTime)
{
	SetReadyState();
}

EGameMainStatus GS_StopBet::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_StopBet::GetNextStatus() const
{
	return EGameStatus::Send;
}