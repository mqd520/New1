// BaccratGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InitService.h"
#include "BaccratService.h"


int _tmain(int argc, _TCHAR* argv[])
{
	InitService::OnMainRun();





	char ch[1024] = { 0 };
	while (true)
	{
		string cmd = gets_s(ch);

		if (cmd == "101")
		{
			vector<int> vec = { 65 };
			BaccratService::GetInstance()->GetGameSrvMgr()->CreateGameService(vec);
		}

		else if (cmd == "201")
		{
			BaccratService::GetInstance()->GetGameSrvMgr()->Get(65)->GetGameStatusMgr()->StartTable();
		}
	}

	InitService::OnMainExit();
	return 0;
}

