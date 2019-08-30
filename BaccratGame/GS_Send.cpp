#include "stdafx.h"
#include "GS_Send.h"

GS_Send::GS_Send(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::Send, isAutoEnterNext, nDurationTime)
{
	SetReadyState();
}

EGameMainStatus GS_Send::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Send::GetNextStatus() const
{
	return EGameStatus::Publish;
}