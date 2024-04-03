/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:01:44 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 18:11:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Fixed.hpp"
# include <cmath>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int &v)
{
	std::cout << "int Constructor called" << std::endl;
	this->value = v << bits;
}

Fixed::Fixed( const Fixed &fixed)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const float &val)
{
	std::cout << "float Constructor called" << std::endl;
	this->value = roundf( val * ( 1 << this->bits ) );
}

Fixed::~Fixed()
{
	std::cout << "Deconstruct called" << std::endl;
}


const Fixed& Fixed::operator=(Fixed const& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits called" << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const val )
{
	std::cout << "setRawBits called" << std::endl;
	this->value = val;
}

float Fixed::toFloat(void) const {
    return ((float)( this->getRawBits() ) / ( 1 << this->bits ));
}

int Fixed::toInt(void) const {
    return this->value >> this->bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fi)
{
	o << fi.toFloat();
	return o;
}
