/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:39:24 by edoardo          ###   ########.fr       */
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
    this->brain = new Brain();
	std::cout << this->type << "  constructor " << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << this->type << " decostrutor  " << std::endl;
}
