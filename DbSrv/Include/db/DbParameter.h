#pragma once

#include <string>
#include <vector>
using namespace std;

namespace db
{
	// database parameter
	class DbParameter
	{
	public:
		DbParameter();
		~DbParameter();

	protected:
		vector<pair<string, string>> vecDbParams;		// db parameters

	public:
		void GetParams(vector<pair<string, string>>& vec);

		void Add(string name, INT16 val);

		void Add(string name, UINT16 val);

		void Add(string name, INT32 val);

		void Add(string name, UINT32 val);

		void Add(string name, INT64 val);

		void Add(string name, UINT64 val);

		//void Add(string name, SHORT val);

		//void Add(string name, USHORT val);

		void Add(string name, BYTE val);

		void Add(string name, float val);

		void Add(string name, double val);

		void Add(string name, string val);
	};
}