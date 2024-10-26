#include "easyfind.hpp"
#include <vector>
#include <list>

int main() 
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);
	if (easyFind(vec, 11) == true)
		std::cout << "found in vector\n";
	if (easyFind(vec, 1112) == false)
		std::cout << "not found in vector\n";
	vec.clear();
	if (easyFind(vec, 11) == false)
		std::cout << "not found in vector\n";
	if (easyFind(vec, 142) == false)
		std::cout << "not found in vector\n";
	vec.push_back(42);
	if (easyFind(vec, 42) == true)
		std::cout << "found in vector\n";

	std::list<int> list;
	list.push_back(110);
	list.push_back(41);
	list.push_back(73);
	list.push_back(34);
	if (easyFind(list, 11) == false)
		std::cout << "not found in list\n";
	if (easyFind(list, 142) == false)
		std::cout << "not found in list\n";
	list.push_back(42);
	if (easyFind(list, 42) == true)
		std::cout << "found in list\n";
	return 0;
}