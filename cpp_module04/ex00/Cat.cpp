/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 13:28:05 by evocatur         ###   ########.fr       */
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

Cat::Cat( const Cat& other ) : Animal("Cat")
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&   Cat::operator=( const Cat& other ) {
    this->type = other.type;
    return *this;
}

Cat::Cat() : Animal("Cat")
{
	std::cout <<"Cat constructor called " << std::endl;
}

Cat::~Cat()
{
    std::cout << "cat decostrutor called" << std::endl;
}
