/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include "Brain.hpp"

# ifndef DOG_H
# define DOG_H

class Dog : public AAnimal
{
    private:
    
    public:
        ~Dog( void );
        Dog( void );
        Dog(std::string _type);
        Dog( const Dog& src );
        Dog& operator=( const Dog& other );

        std::string getType() const;
        void makeSound() const;
};

#endif