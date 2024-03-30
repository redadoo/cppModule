
#include<string>
#include<iostream>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap
{
    private:
        int         hitPoint;
        int         energyPoints;
        int         attackDamage;

    public:
        std::string name;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getAttackDamage();
        const std::string getName();
        ClapTrap(std::string name);
        ~ClapTrap();
};

#endif