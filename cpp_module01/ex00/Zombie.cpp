#include "Zombie.hpp"


void Zombie::announce ()
{
	std::cout << name << ": " << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "the zombie : " << name << " is dead" << std::endl;
}