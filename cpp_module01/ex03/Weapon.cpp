/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:28 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:28 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}


void Weapon::setType(std::string newType)
{
    this->type = newType;
}

const std::string& Weapon::getType()
{
    return this->type;
}