#pragma once

// init service
class InitService final
{
private:
	InitService();

public:
	//************************************
	// Method:    Main Run evt handle
	//************************************
	static void OnMainRun();

	//************************************
	// Method:    Main Exit evt handle
	//************************************
	static void OnMainExit();
};