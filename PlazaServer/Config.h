#pragma once

#include "SendCardSection.h"
#include "TableSection.h"
#include "DbServiceSection.h"


// config
class Config
{
public:
	Config(string strFilePath);

private:
	string strFilePath;		// ini file path

public:
	const SendCardSection sendcard;		// SendCard Section
	const TableSection table;			// Table Section
	const DbServiceSection dbSrv;		// db service section

public:
	//************************************
	// Method:    ��ʼ��
	//************************************
	void Init() const;
};

extern const Config _cfg;	// the unique Config instance