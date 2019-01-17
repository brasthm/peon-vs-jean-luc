#ifndef UTILS_H
#define UTILS_H

#include <vector>

namespace Utils
{
	template<class t> bool contains(std::vector<t> &vect, t value)
	{
		for (auto e : vect)
			if (e == value)
				return true;
		return false;
	}
}

#endif // !UTILS_H
