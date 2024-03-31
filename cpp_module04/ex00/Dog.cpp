/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:04:54 by edoardo          ###   ########.fr       */
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

Dog::Dog() : Animal("Dog")
{
	std::cout << this->type << "  constructor " << std::endl;
}

Dog::Dog( const Dog& rhs ) : Animal("Dog")
{
    *this = rhs;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&   Dog::operator=( const Dog& rhs ) {
    this->type = rhs.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << this->type << " decostrutor  " << std::endl;
}
