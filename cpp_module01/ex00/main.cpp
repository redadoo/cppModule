#include "Zombie.hpp"


int main()
{
	std::string name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "Zombie name: " << std::endl;
	std::cin >> name;

	Zombie zombie1(name);
	
	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Zombie name: " << std::endl;
	std::cin >> name;

	Zombie *zombi2 = newZombie(name);
	zombi2->announce();
	delete zombi2;

	std::cout << " Calling randomChump(). " << std::endl;
	randomChump("randi");
}