#pragma once

// init service
class InitService final
{
private:
	InitService();

public:
	//************************************
	// Method:    main���������¼�����
	//************************************
	static void OnMainRun();

	//************************************
	// Method:    main�����˳��¼�����
	//************************************
	static void OnMainExit();
};