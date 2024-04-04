/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:42:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:42:18 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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