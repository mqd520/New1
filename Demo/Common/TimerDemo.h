#pragma once

#include "com/Timer.h"
using namespace com;


class TimerDemo final
{
private:
	TimerDemo();

public:
	static void Init();

	static void Start();

	static void Pause();

	static void Resume();

	static void Stop();

	static void Restart();

	static void Exit();
};