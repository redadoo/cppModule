/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:42:06 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:42:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int main()
{
	size_t i = 5;

	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second FragTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap(name1);
	FragTrap fragTrap(name2);


	clapTrap.attack(fragTrap.getName());
	fragTrap.takeDamage(clapTrap.getAttackDamage());

	fragTrap.attack(clapTrap.getName());
	clapTrap.takeDamage(fragTrap.getAttackDamage());

	while (i)
	{
		fragTrap.attack(clapTrap.getName());
		clapTrap.takeDamage(fragTrap.getAttackDamage());
		i--;
	}

	fragTrap.highFivesGuys();
}