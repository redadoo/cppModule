/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:08:46 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal("WrongCat")
{
    *this = other;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&   WrongCat::operator=( const WrongCat& other ) {
    this->type = other.type;
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << this->type << " destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}