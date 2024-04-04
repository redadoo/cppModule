/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:37 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:41:37 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int main()
{
	size_t i = 7;
	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second ScavTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap(name1);
	ScavTrap scavTrap(name2);


	clapTrap.attack(scavTrap.getName());
	scavTrap.takeDamage(clapTrap.getAttackDamage());

	clapTrap.beRepaired(1);
	while (i)
	{
		scavTrap.attack(clapTrap.getName());
		clapTrap.takeDamage(scavTrap.getAttackDamage());
		i--;
	}

	scavTrap.guardGate();
}