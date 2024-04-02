/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/02 12:26:39 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int &v);
		Fixed(const float &v);
		Fixed( const Fixed &fixed);
		const Fixed &operator=(Fixed const &fixed);
		
		~Fixed();

		bool    operator>( const Fixed &rhs ) const ;
		bool    operator<( const Fixed &rhs ) const ;
		bool    operator>=( const Fixed &rhs ) const ;
		bool    operator<=( const Fixed &rhs ) const ;
		bool    operator==( const Fixed &rhs ) const ;
		bool    operator!=( const Fixed &rhs ) const ;

		Fixed   operator+( const Fixed &rhs ) const ;
		Fixed   operator-( const Fixed &rhs ) const ;
		Fixed   operator*( const Fixed &rhs ) const ;
		Fixed   operator/( const Fixed &rhs ) const ;

		Fixed&  operator++( void ); // pre
		Fixed   operator++( int ); // post
		Fixed&  operator--( void ); // pre
		Fixed   operator--( int ); // post

		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float   toFloat( void ) const;
		int     toInt( void ) const;

};
	std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif