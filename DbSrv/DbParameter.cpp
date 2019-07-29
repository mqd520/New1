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
		char ch[10] = { 0 };
		_itoa_s(val, ch, 10);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, UINT16 val)
	{
		char ch[10] = { 0 };
		_itoa_s(val, ch, 10);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, INT32 val)
	{
		char ch[10] = { 0 };
		_itoa_s(val, ch, 10);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, UINT32 val)
	{
		char ch[10] = { 0 };
		_itoa_s(val, ch, 10);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, INT64 val)
	{
		char ch[10] = { 0 };
		sprintf_s(ch, "%d", val);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, UINT64 val)
	{
		char ch[10] = { 0 };
		sprintf_s(ch, "%d", val);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, BYTE val)
	{
		char ch[10] = { 0 };
		_itoa_s(val, ch, 10);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, float val)
	{
		char ch[10] = { 0 };
		sprintf_s(ch, "%f", val);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, double val)
	{
		char ch[10] = { 0 };
		sprintf_s(ch, "%f", val);
		vecDbParams.push_back({ name, ch });
	}

	void DbParameter::Add(string name, string val)
	{
		vecDbParams.push_back({ name, val });
	}

	void DbParameter::Add(string name, bool val)
	{
		char ch[10] = { 0 };
		sprintf_s(ch, "%s", val ? "True" : "False");
		vecDbParams.push_back({ name, ch });
	}
}