/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:09 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/13 13:27:36 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Initializate FragTrap : "<< this->name << std::endl;
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
