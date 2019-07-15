#include "stdafx.h"
#include "Include/db/DbParameter.h"

namespace db
{
	DbParameter::DbParameter()
	{

	}

	DbParameter::~DbParameter()
	{

	}

	void DbParameter::GetParams(vector<pair<string, string>>& vec)
	{
		for (vector<pair<string, string>>::iterator it = vecDbParams.begin(); it != vecDbParams.end(); it++)
		{
			vec.push_back(*it);
		}
	}

	void DbParameter::Add(string name, INT16 val)
	{
		vecDbParams.push_back({ name, "value" });
	}
}