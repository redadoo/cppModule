/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:41 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:46:30 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::announce ()
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead " <<std::endl;
}