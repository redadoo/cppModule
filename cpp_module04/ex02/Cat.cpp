/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:35:49 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:39:16 by edoardo          ###   ########.fr       */
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

Cat::Cat() : AAnimal("Cat")
{
    this->brain = new Brain();
	std::cout << this->type << "  constructor " << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << this->type << " decostrutor  " << std::endl;
}
