
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

class ScavTrap : public ClapTrap
{
    
    private:
    
    public:
        ScavTrap(std::string name);
        ~ScavTrap(); 
        void guardGate();
};


#endif