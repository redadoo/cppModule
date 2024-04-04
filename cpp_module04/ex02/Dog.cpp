/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string Dog::getType() const
{
    return this->type;
}

void Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

Dog::Dog() : AAnimal("Dog")
{
	std::cout << this->type << "  constructor " << std::endl;
}

Dog::Dog( const Dog& other ) : AAnimal("Dog")
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&   Dog::operator=( const Dog& other ) {
    this->type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << this->type << " decostrutor  " << std::endl;
}
