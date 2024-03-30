#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>

template <typename T> int easyfind(T container, int value)
{
	if ( std::find( container.begin(), container.end(), value ) != container.end() )
		return 1;
	else
		return 0;
}

#endif