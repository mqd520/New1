// BaccratGame.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "InitService.h"
#include "BaccratService.h"


int _tmain(int argc, _TCHAR* argv[])
{
	InitService::OnMainRun();





	while (true)
	{
		getchar();

		vector<int> vec = { 65 };
		BaccratService::GetInstance()->GetGameSrvMgr()->CreateGameService(vec);
	}

	InitService::OnMainExit();
	return 0;
}

