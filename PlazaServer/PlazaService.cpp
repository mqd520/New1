#include "stdafx.h"
#include "PlazaService.h"


PlazaService* pInstance = NULL;	// the unique CenterService instance

PlazaService::PlazaService()
{

}

PlazaService* PlazaService::GetInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new PlazaService();
	}

	return pInstance;
}

void PlazaService::Init()
{

}

void PlazaService::Exit()
{

}