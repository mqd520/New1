#include "stdafx.h"
#include "GS_Publish.h"

GS_Publish::GS_Publish(bool isAutoEnterNext, int nDurationTime) :
GameStatus(EGameStatus::Publish, isAutoEnterNext, nDurationTime)
{
	SetReadyState();
}

EGameMainStatus GS_Publish::GetCurGameMainStatus() const
{
	return EGameMainStatus::Running;
}

EGameStatus GS_Publish::GetNextStatus() const
{
	return EGameStatus::Settle;
}