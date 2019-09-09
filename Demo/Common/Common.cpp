// Common.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "StringDemo.h"

#include "ByteStreamDemo.h"
#include "MemoryStreamDemo.h"
#include "StreamToolDemo.h"
#include "NetworkStreamDemo.h"
#include "NetworkStreamReadDemo.h"
#include "NetworkStreamWriteDemo.h"

#include "ThreadDemo.h"

#include "TimerDemo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//printf("long: %d, short: %d \n", sizeof(long), sizeof(short));


	//printf("Local host endian: %d \n", StreamTool::GetLocalHostEndian());


	//BYTE buf1[] = { 1, 2, 3 };
	//BYTE buf2[] = { 0, 0, 0 };
	//memcpy(buf2, buf1, 3);
	//printf("buf2: %d, %d, %d \n", buf2[0], buf2[1], buf2[2]);


	TimerDemo::Init();



	char ch[1024] = { 0 };
	while (true)
	{
		string cmd = gets_s(ch);
		if (cmd == "exit")
		{
			ThreadDemo::Exit();

			break;
		}

		else if (cmd == "start")
		{
			TimerDemo::Start();
		}
		else if (cmd == "pause")
		{
			TimerDemo::Pause();
		}
		else if (cmd == "resume")
		{
			TimerDemo::Resume();
		}
		else if (cmd == "stop")
		{
			TimerDemo::Stop();
		}
		else if (cmd == "restart")
		{
			TimerDemo::Restart();
		}
		else if (cmd == "exit1")
		{
			TimerDemo::Exit();
		}
	}


	printf("Main over \n");
	::Sleep(3 * 1000);

	return 0;
}