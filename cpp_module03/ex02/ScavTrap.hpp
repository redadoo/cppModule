
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

class ScavTrap : public ClapTrap
{
    
    private:
    
    public:
        void attack(const std::string& target);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &rhs);

        ScavTrap &operator=(const ScavTrap& rhs);
        ~ScavTrap(); 
        void guardGate();
};


#endif