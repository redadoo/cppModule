
#include <string>
#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
	private:
		std::string type;
		
	public:
		Weapon(std::string type);

		const std::string& getType();
		void setType(std::string newType);
};

#endif