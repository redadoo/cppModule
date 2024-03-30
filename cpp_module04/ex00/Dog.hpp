/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:01:54 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

# ifndef DOG_H
# define DOG_H

class Dog : public Animal
{
    private:
    
    public:
        ~Dog( void );
        Dog( void );
        Dog(std::string _type);
        
        std::string getType() const;
        void makeSound() const;
};

#endif