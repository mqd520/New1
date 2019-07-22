#pragma once

#include "GameCenterSection.h"
#include "DbServiceSection.h"


// config
class Config
{
public:
	Config(string strFilePath);

private:
	string strFilePath;		// ini file path

public:
	const GameCenterSection gamecenter;		// game center Section
	const DbServiceSection dbSrv;			// db service section

public:
	//************************************
	// Method:    ��ʼ��
	//************************************
	void Init() const;
};

extern const Config _cfg;	// the unique Config instance