/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:26 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:41:26 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main()
{
	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second ClapTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap1(name1);
	ClapTrap clapTrap2(name2);


	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	clapTrap2.beRepaired(1);
}