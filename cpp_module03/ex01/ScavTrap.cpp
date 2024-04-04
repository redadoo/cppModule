/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:48:54 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 11:42:24 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap : "<< this->name << "is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Initializate ScavTrap : "<< this->name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0)
	{
		std::cout << "ScavTrap : " << this->name <<" attacks " << target << " causing "<< this->attackDamage <<" points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap : " << this->name << " attack "<< target <<" but has no energy "<< std::endl;
	}
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs.name)
{
    *this = rhs;
    std::cout << "ScavTrap copy constructor called" << std::endl;
    return;
}

ScavTrap&   ScavTrap::operator=( const ScavTrap& rhs ) {
    this->name = rhs.name;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "destroy ScavTrap : "<< this->name << std::endl;
}
