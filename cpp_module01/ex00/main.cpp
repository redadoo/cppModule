/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:55 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:54:23 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	std::string name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "Zombie name: " << std::endl;
	std::cin >> name;

	Zombie zombie1(name);
	
	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Zombie name: " << std::endl;
	std::cin >> name;

	Zombie *zombi2 = newZombie(name);
	zombi2->announce();

	std::cout << "Creating zombie with random chump." << std::endl;
	std::cout << "Zombie name: " << std::endl;
	std::cin >> name;
	randomChump(name);
	
	delete zombi2;
}