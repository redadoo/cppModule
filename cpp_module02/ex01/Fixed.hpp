/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 16:53:10 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIDEX_HPP
# define FIDEX_HPP

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
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
        const Fixed &operator=(Fixed const &fixed);
};

#endif