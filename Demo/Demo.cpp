// Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "HttpClientDemo.h"
#include "WebSocket.h"


int _tmain(int argc, _TCHAR* argv[])
{

	//HttpClientDemo::Demo();
	WebSocket::Init();


	while (true)
	{
		getchar();
	}
	
	return 0;
}