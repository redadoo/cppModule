/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:09 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Initializate FragTrap : "<< this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name)
{
    *this = other;
    std::cout << "FragTrap copy constructor called" << std::endl;
    return;
}

FragTrap&   FragTrap::operator=( const FragTrap& other ) {
    this->name = other.name;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "destroy FragTrap : "<< this->name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "give me five"<< std::endl;
    std::cout << "         _.-._" << std::endl;
    std::cout << "        | | | |_" << std::endl;
    std::cout << "        | | | | |" << std::endl;
    std::cout << "        | | | | |" << std::endl;
    std::cout << "      _ |  '-._ |" << std::endl;
    std::cout << "      \\`\\`-.'-._;" << std::endl;
    std::cout << "       \\    '   |" << std::endl;
    std::cout << "        \\  .`  /" << std::endl;
    std::cout << "         |    |" << std::endl;
}
