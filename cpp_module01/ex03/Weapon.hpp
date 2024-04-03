/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:30 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:30 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
	private:
		std::string type;
		
	public:
		Weapon(std::string type);

		const std::string& getType();
		void setType(std::string newType);
};

#endif