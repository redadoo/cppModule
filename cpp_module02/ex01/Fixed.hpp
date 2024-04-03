/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 18:13:27 by evocatur         ###   ########.fr       */
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
		~Fixed();

		const Fixed &operator=(Fixed const &fixed);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		int     toInt( void ) const;
		float   toFloat( void ) const;

};
	std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif