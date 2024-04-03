/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:15 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 14:02:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon& _weapon ) : weapon(_weapon)
{
    this->name = _name;
}

HumanA::~HumanA() {}

void    HumanA::attack( ) {
    if (this->weapon.getType() == "") {
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
    } else {
        std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
    }
}