#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_H
#define HUMANA_H

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;
    	HumanA();
		
	public:
    	HumanA( std::string name, Weapon& weapon );
    	~HumanA();
		
		void 	attack();
};


#endif