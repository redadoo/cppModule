#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_H
#define HUMANB_H

class HumanB
{
	private:
		Weapon		*weapon;
		std::string name;

	public:
		HumanB(std::string name);
		void	attack();
    	void    setWeapon( Weapon& weapon );	
};
#endif