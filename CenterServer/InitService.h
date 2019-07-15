#pragma once

// init service
class InitService final
{
private:
	InitService();

public:
	//************************************
	// Method:    main函数运行事件处理
	//************************************
	static void OnMainRun();

	//************************************
	// Method:    main函数退出事件处理
	//************************************
	static void OnMainExit();
};