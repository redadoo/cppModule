/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:01:44 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 18:28:36 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Fixed.hpp"
# include <cmath>

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const int &v)
{
    this->value = v << bits;
}

Fixed::Fixed( const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const float &v)
{
    this->value = roundf(v*( 1 << bits));
}

Fixed::~Fixed() {}


const Fixed& Fixed::operator=(Fixed const& fixed)
{
    this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->value;
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float Fixed::toFloat(void) const {
    return (float( this->getRawBits() ) / ( 1 << this->bits ));
}

int Fixed::toInt(void) const {
    return this->value >> this->bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fix)
{
	o << fix.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed( this->toFloat() + other.toFloat() );
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed( this->toFloat() - other.toFloat() );
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed( this->toFloat() * other.toFloat() );
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other.toFloat() == 0)
        throw std::invalid_argument("Division by zero");
	return Fixed( this->toFloat() / other.toFloat() );
}

Fixed &Fixed::operator++() {
    ++this->value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
