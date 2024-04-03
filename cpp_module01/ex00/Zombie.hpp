/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:40:25 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:40:25 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
	private:
		std::string name;
	
	public:
		void announce( void );
		
		Zombie(std::string name);
		~Zombie();
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif