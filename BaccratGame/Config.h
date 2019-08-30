#pragma once

#include "GameCenterSection.h"
#include "DbServiceSection.h"
#include "TableSection.h"


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
	const TableSection table;				// table section

public:
	//************************************
	// Method:    ≥ı ºªØ
	//************************************
	void Init() const;
};

extern const Config _cfg;	// the unique Config instance