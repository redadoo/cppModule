/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:47 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 13:27:56 by evocatur         ###   ########.fr       */
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
	std::cout << "Animal  constructor called " << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal constructor  called " << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal&   Animal::operator=( const Animal& other ) {
    this->type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "animal decostrutor  called" << std::endl;
}