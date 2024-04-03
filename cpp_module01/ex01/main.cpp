/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:39 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:39 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	std::string name;
	int			zombieCount;
	std::cout << "Creating zombie horde" << std::endl;
	std::cout << "Zombie's horde name: " << std::flush;
	std::cin >> name;
	std::cout << "Zombie's number: " << std::flush;
	std::cin >> zombieCount;

	Zombie *horde = zombieHorde(zombieCount,name);
	
	for (int i = 0; i < zombieCount; i++)
	{
		horde[i].announce();
	}
	
    delete [] horde;	
}