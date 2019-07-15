#include "stdafx.h"
#include "Include/db/DbServiceApp.h"

#include "hc/HttpClientApp.h"
using namespace hc;


namespace db
{
	string DbServiceApp::addr = "127.0.0.1";

	DbServiceApp::DbServiceApp()
	{

	}

	void DbServiceApp::Init()
	{
		HttpClientApp::Init();
	}

	void DbServiceApp::Exit()
	{
		HttpClientApp::Exit();
	}

	void DbServiceApp::SetDbSrvAddr(string addr)
	{
		DbServiceApp::addr = addr;
	}

	string DbServiceApp::GetDbSrvAddr()
	{
		return addr;
	}
}