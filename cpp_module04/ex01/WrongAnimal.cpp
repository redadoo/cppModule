/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:42 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 14:57:53 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type( "WrongAnimel" ) {
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type )
{
    std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& rhs ) 
{
    *this = rhs;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&   WrongAnimal::operator=( const WrongAnimal& rhs ) {
    this->type = rhs.type;
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