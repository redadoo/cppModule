/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 14:18:13 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AAnimal.hpp"

#ifndef CAT_H
# define CAT_H

class Cat : public AAnimal
{
    private:
        Brain *brain;
    public:
        ~Cat();
        Cat();
        Cat( const Cat& src );
        Cat& operator=( const Cat& other );

        std::string getType() const;
        void makeSound() const;
};

#endif