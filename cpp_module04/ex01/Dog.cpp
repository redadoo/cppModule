/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 14:00:51 by evocatur         ###   ########.fr       */
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
	std::cout << "Dog  constructor called " << std::endl;
    brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal("Dog")
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&   Dog::operator=( const Dog& other ) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog()
{
    std::cout << "dog decostrutor called" << std::endl;
    delete brain;
}
