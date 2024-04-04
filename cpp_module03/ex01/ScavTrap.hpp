/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:46 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:41:47 by evocatur         ###   ########.fr       */
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