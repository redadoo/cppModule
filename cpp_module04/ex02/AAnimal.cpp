/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.Cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:38:40 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"


std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::makeSound() const
{
    std::cout << "I am a Animal" << std::endl;
}

AAnimal::AAnimal()
{
	std::cout << this->type << "  constructor " << std::endl;
}

AAnimal::AAnimal(std::string _type) : type(_type)
{
	std::cout << this->type << "  constructor " << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << this->type << " decostrutor  " << std::endl;
}