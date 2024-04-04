/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:00 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 13:34:14 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIML_H
#define WRONGANIML_H

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal( std::string type );
    WrongAnimal( const WrongAnimal& src );
    WrongAnimal& operator=( const WrongAnimal& other );
    virtual ~WrongAnimal( void );

    void            makeSound( void ) const;
    std::string     getType( void ) const; 
};

#endif