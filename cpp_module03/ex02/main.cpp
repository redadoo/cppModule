
#include "FragTrap.hpp"

int main()
{
	std::string nameClapTrap;
	std::string namefragtrap;

	std::cout << "Create one ClapTrap" << std::endl;
	std::cin >> nameClapTrap;

	std::cout << "Create one FragTrap" << std::endl;
	std::cin >> namefragtrap;

	ClapTrap clapTrap(nameClapTrap);
	FragTrap fragtrap(namefragtrap);

	
}