/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:04:45 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

std::string Cat::getType() const
{
    return this->type;
}

void Cat::makeSound() const
{
	std::cout << "miao miao" << std::endl;
}

Cat::Cat( const Cat& rhs ) : AAnimal("Cat")
{
    *this = rhs;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&   Cat::operator=( const Cat& rhs ) {
    this->type = rhs.type;
    return *this;
}

Cat::Cat() : AAnimal("Cat")
{
	std::cout << this->type << "  constructor " << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type << " decostrutor  " << std::endl;
}
