/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:08:46 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 14:59:24 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& rhs ) : WrongAnimal("WrongCat")
{
    *this = rhs;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&   WrongCat::operator=( const WrongCat& rhs ) {
    this->type = rhs.type;
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