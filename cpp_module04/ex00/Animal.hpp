/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:00:41 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_H
#define ANIMAL_H

#include<string>
#include<iostream>

class Animal
{
    protected:
        std::string type;
    private:
    
    public:
        virtual std::string getType() const;
        virtual void makeSound() const;
        virtual ~Animal();
        Animal( void );
        Animal( std::string _type);
};

#endif