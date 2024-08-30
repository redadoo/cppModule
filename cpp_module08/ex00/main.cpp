#include "easyfind.hpp"
#include <vector>

int main() 
{

	std::vector<int> vec;
	std::vector<int> emptyVec;

	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);

	if (easyFind(vec, 11) == true)
		std::cout << "found\n";

	if (easyFind(vec, 1112) == false)
		std::cout << "not found\n";
	
	vec.clear();
	
	if (easyFind(vec, 42) == false)
		std::cout << "not found\n";

	if (easyFind(emptyVec, 142) == false)
		std::cout << "not found\n";

	return 0;
}
