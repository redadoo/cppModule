
#include "ScavTrap.hpp"

int main()
{
	std::string nameClapTrap;
	std::string nameScavTrap;

	std::cout << "Create one ClapTrap" << std::endl;
	std::cin >> nameClapTrap;

	std::cout << "Create one ScavTrap" << std::endl;
	std::cin >> nameScavTrap;

	ClapTrap clapTrap(nameClapTrap);
	ScavTrap scavTrap(nameScavTrap);

	
}