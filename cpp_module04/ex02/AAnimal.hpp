/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:37:11 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AANIMAL_H
#define AANIMAL_H

#include<iostream>

class AAnimal
{
    protected:
        std::string type;    
    public:
        virtual std::string getType() const;
        virtual void makeSound() const = 0;
        virtual ~AAnimal();
        AAnimal( void );
        AAnimal( std::string _type);
};

#endif