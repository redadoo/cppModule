
#include "FragTrap.hpp"

int main()
{
	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second FragTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap(name1);
	FragTrap fragTrap(name2);


	clapTrap.attack(fragTrap.getName());
	fragTrap.takeDamage(clapTrap.getAttackDamage());

	fragTrap.attack(clapTrap.getName());
	clapTrap.takeDamage(fragTrap.getAttackDamage());

	fragTrap.highFivesGuys();
}