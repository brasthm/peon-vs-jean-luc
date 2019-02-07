#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

namespace Utils
{
	template<class t> bool contains(std::vector<t> &vect, t value)
	{
		for (auto e : vect)
			if (e == value)
				return true;
		return false;
	}

	std::vector<std::string> split(const std::string& str, const std::string& sep = " ");
}

#endif // !UTILS_H
