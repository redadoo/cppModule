#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void ) {

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);

	if (easyfind(vec,11) == true)
		std::cout << "found\n";
	if (easyfind(vec,1112) == false)
		std::cout << "not found\n";
	return 0;
}
