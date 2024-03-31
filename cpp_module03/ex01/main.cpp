
#include "ScavTrap.hpp"

int main()
{
	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second ScavTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap(name1);
	ScavTrap scavTrap(name2);


	clapTrap.attack(scavTrap.getName());
	scavTrap.takeDamage(clapTrap.getAttackDamage());

	scavTrap.attack(clapTrap.getName());
	clapTrap.takeDamage(scavTrap.getAttackDamage());

	scavTrap.guardGate();
}