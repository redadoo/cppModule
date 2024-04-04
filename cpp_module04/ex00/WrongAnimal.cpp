/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:42 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 13:29:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type( "WrongAnimal" ) {
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type )
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) 
{
    *this = other;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&   WrongAnimal::operator=( const WrongAnimal& other ) {
    this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "I am a WrongAnimal" << std::endl;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->type;
}