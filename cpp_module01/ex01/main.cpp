#include "Zombie.hpp"


int main()
{
	std::string name;
	int			zombieCount;
	std::cout << "Creating zombie horde" << std::endl;
	std::cout << "Zombie's horde name: " << std::flush;
	std::cin >> name;
	std::cout << "Zombie's number: " << std::flush;
	std::cin >> zombieCount;

	Zombie *horde = zombieHorde(zombieCount,name);
	
	for (int i = 0; i < zombieCount; i++)
	{
		horde[i].announce();
	}
	
    delete [] horde;	
}