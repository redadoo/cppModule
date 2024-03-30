#include "Zombie.hpp"


void Zombie::announce ()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << std::endl;
}