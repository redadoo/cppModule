
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void    HumanB::setWeapon( Weapon& weapon ) {
    this->weapon = &weapon;
}
void    HumanB::attack() 
{
	if (this->weapon != NULL && this->weapon->getType() != "") {
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	} else {
		std::cout << name << " doesn't have a weapon to attack." << std::endl;
	}
}
