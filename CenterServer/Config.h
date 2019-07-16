#pragma once

#include "DbSection.h"
#include "SendCardSection.h"
#include "TableSection.h"
#include "PlazaSection.h"
#include "BAAdminWebSiteSection.h"


// config
class Config
{
public:
	Config(string strFilePath);

private:
	string strFilePath;		// ini file path

public:
	const DbSection db;					// Db Section
	const SendCardSection sendcard;		// SendCard Section
	const TableSection table;			// Table Section
	const PlazaSection plaza;			// Plaza Section
	const BAAdminWebSiteSection ba;		// backstage admin website section

public:
	//************************************
	// Method:    ≥ı ºªØ
	//************************************
	void Init() const;
};

extern const Config _cfg;	// the unique Config instance