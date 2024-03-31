/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:47 by edoardo           #+#    #+#             */
/*   Updated: 2024/03/31 04:14:35 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "I am a Animal" << std::endl;
}

Animal::Animal()
{
	std::cout << this->type << "  constructor " << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << this->type << "  constructor " << std::endl;
}

Animal::~Animal()
{
    std::cout << this->type << " decostrutor  " << std::endl;
}