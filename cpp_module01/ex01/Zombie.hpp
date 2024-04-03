/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:46 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:46:24 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
	private:
		std::string name;
	
	public:
		void announce( void );
		void SetName(std::string name);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif