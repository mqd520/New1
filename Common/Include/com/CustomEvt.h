#pragma once

#include <vector>
using namespace std;

namespace com
{
	// Custom evt
	template<class T>
	class CustomEvt
	{
	protected:
		vector<T> vecFns;	// callback list

	protected:
		virtual void TriggerEvt()
		{
			for (vector<T>::iterator it = vecFns.begin(); it != vecFns.end(); it++)
			{
				if ((*it)._Empty())
				{
					(*it)();
				}
			}
		};

	public:
		virtual void RegEvt(T callback)
		{
			bool b = false;
			for (vector<T>::iterator it = vecFns.begin(); it != vecFns.end(); it++)
			{
				if (*it == callback)
				{
					b = true;
					break;
				}
			}

			if (!b)
			{
				vecFns.push_back(callback);
			}
		};

		virtual void RemoveEvt(T callback)
		{
			vector<T>::iterator it = find(vecFns.begin(), vecFns.end(), callback);
			if (it != vecFns.end())
			{
				vecFns.erase(it);
			}
		};

		virtual void RemoveEvt()
		{
			vecFns.clear();
		};
	};
}