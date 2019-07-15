#pragma once

#include <string>
using namespace std;


namespace db
{
	// DbServiceApp
	class DbServiceApp final
	{
	private:
		DbServiceApp();

	private:
		static string addr;		// db service addr

	public:
		//************************************
		// Method:    Init
		//************************************
		static void Init();

		//************************************
		// Method:    Exit
		//************************************
		static void Exit();

		//************************************
		// Method:    Set db service addr
		// Parameter: string addr
		//************************************
		static void SetDbSrvAddr(string addr);

		//************************************
		// Method:    Get db service addr
		//************************************
		static string GetDbSrvAddr();
	};
}