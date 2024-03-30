/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/20 15:45:13 by edoardo          ###   ########.fr       */
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
		Fixed( Fixed &fixed);
		~Fixed();
		
		const Fixed &operator=(Fixed const &fixed);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif