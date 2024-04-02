/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:01:44 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/02 11:48:40 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Fixed.hpp"
# include <cmath>

Fixed::Fixed() : value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int &v): value(v << bits )
{
	std::cout << "int Constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const float &v) : value( roundf( v * ( 1 << bits ) ))
{
	std::cout << "float Constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstruct called" << std::endl;
}


const Fixed& Fixed::operator=(Fixed const& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return *this;
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

float Fixed::toFloat(void) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << this->bits );
}

int Fixed::toInt(void) const {
    return this->value >> this->bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}
