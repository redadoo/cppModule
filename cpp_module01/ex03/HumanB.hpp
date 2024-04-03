/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:22 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_H
#define HUMANB_H

class HumanB
{
	private:
		Weapon		*weapon;
		std::string name;

	public:
		HumanB(std::string name);
		void	attack();
    	void    setWeapon( Weapon& weapon );	
};
#endif