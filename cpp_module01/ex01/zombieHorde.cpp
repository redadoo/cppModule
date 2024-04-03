/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:48 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:46:58 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int n, std::string name )
{
	Zombie *horde; 
	
	horde = new Zombie[n];
	for (int i = 0; i < n; i++) { horde[i].SetName(name);}
	return horde;
}