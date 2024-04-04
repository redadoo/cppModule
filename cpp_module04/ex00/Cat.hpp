/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

# ifndef CAT_H
# define CAT_H

class Cat : public Animal
{
    private:
    
    public:
        ~Cat();
        Cat();
        Cat( const Cat& src );
        Cat& operator=( const Cat& other );

        std::string getType() const;
        void makeSound() const;
};

#endif