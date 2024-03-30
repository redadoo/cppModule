#include "Zombie.hpp"

Zombie* zombieHorde( int n, std::string name )
{
	Zombie *zombiz = new Zombie[n];

	for (int i = 0; i < n; i++) 
	{
		zombiz[i].SetName(name);
	}
	
	return zombiz;
}