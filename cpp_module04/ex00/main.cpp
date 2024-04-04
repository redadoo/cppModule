/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:20 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 13:30:32 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "constructor : \n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    const WrongAnimal* x = new WrongAnimal();
    const WrongAnimal* z = new WrongCat();

    std::cout << "\ntype : \n" << std::endl;
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << x->getType() << " " << std::endl;
    std::cout << z->getType() << " " << std::endl;

    std::cout << "sound : \n" << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    x->makeSound();
    z->makeSound();

    delete meta;
    delete j;
    delete i;
    delete x;
    delete z;

    return 0; 
}