#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T> bool easyFind(T container, int value)
{
	if (std::find( container.begin(), container.end(), value ) != container.end())
		return true;
	else
		return false;
}

#endif