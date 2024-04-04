/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 14:19:48 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"


std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::makeSound() const
{
    std::cout << "I am a AAnimal" << std::endl;
}

AAnimal::AAnimal()
{
	std::cout << "AAnimal  constructor called " << std::endl;
}

AAnimal::AAnimal(std::string _type) : type(_type)
{
	std::cout << "AAnimal constructor  called " << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal decostrutor  called" << std::endl;
}