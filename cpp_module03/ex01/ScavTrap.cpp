/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:48:54 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/13 12:56:21 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap : "<< this->name << "is now in is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Initializate ScavTrap : "<< this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "destroy ScavTrap : "<< this->name << std::endl;
}
