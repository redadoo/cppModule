/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:17 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:18 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_H
#define HUMANA_H

class HumanA
{
	private:
		std::string name;
		Weapon		&weapon;
    	HumanA();
		
	public:
    	HumanA( std::string name, Weapon& weapon );
    	~HumanA();
		
		void 	attack();
};


#endif