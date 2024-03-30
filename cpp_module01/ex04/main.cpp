#include "Replacer.hpp"

int main()
{
	std::string filename;
	std::string s1;
	std::string s2;

	std::cout << "write the filename : " << std::endl;
	std::cin >> filename;

	std::cout << "string to replace : " << std::endl;
    std::cin >> s1;

	std::cout << "replace for the string : " << std::endl;
    std::cin >> s2;

	Replacer replacer(filename,s1,s2);
}
