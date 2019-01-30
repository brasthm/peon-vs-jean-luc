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

	std::vector<std::string> split(const std::string& str, const std::string& sep = " ")
	{
		std::vector<std::string> out;
		size_t debut = 0;
		size_t fin = str.find(sep);
		while (debut <= str.length())
		{
			out.push_back(str.substr(debut, fin - debut));
			debut = fin != std::string::npos ? fin + sep.length() : fin;
			fin = str.find(sep, debut);
		}
		return out;
	}
}

#endif // !UTILS_H
