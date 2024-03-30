/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:01:44 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 17:49:47 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed( Fixed &fixed)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->value = 0;
	fixed.value = this->value;
}

Fixed::~Fixed()
{	
	std::cout << "Decostructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits called" << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits called" << std::endl;
	this->value = raw;
}


const Fixed& Fixed::operator=(Fixed const& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
    {
        this->value = fixed.getRawBits();
    }
    return *this;
}