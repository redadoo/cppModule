/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/13 15:01:01 by edoardo          ###   ########.fr       */
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
        Cat& operator=( const Cat& rhs );

        std::string getType() const;
        void makeSound() const;
};

#endif