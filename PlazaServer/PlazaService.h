#pragma once

// Plaza Service
class PlazaService final
{
private:
	PlazaService();

public:
	//************************************
	// Method:    Get the origin PlazaService instance
	//************************************
	static PlazaService* GetInstance();

public:
	//************************************
	// Method:    Init
	//************************************
	void Init();

	//************************************
	// Method:    Exit
	//************************************
	void Exit();
};