/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:34:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:12:58 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Brain.hpp"

# ifndef CAT_H
# define CAT_H

class Cat : public Animal
{
    private:
        Brain *brain;
        
    public:
        ~Cat();
        Cat();
        
        std::string getType() const;
        void makeSound() const;
};

#endif