// PlazaServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "InitService.h"


int _tmain(int argc, _TCHAR* argv[])
{
	InitService::OnMainRun();



	while (true)
	{
		getchar();
	}


	InitService::OnMainExit();
	return 0;
}