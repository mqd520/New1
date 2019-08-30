#include "stdafx.h"
#include "GS_Settle.h"

GS_Settle::GS_Settle(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::Settle, isAutoEnterNext, nDurationTime)
{
	SetReadyState();
}

EGameMainStatus GS_Settle::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Settle::GetNextStatus() const
{
	return EGameStatus::Prepare;
}