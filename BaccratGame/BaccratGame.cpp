// BaccratGame.cpp : �������̨Ӧ�ó������ڵ㡣
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

		else if (cmd == "201")	// dealer enter game
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(65);
			pSrv->GetDealerMgr()->DealerEnterGame("30001����");
		}

		else if (cmd == "301")	// start table
		{
			GameService* pSrv = BaccratService::GetInstance()->GetGameSrvMgr()->GetGameSrv(65);
			pSrv->GetGameProcess()->StartTable();
		}
	}

	InitService::OnMainExit();
	return 0;
}

