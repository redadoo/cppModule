/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:20 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 14:10:26 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N 100 

int main()
{
    Dog basicDog;
    {
        Dog tmp = basicDog;
    }

    Cat basicCat;
    {
        Cat tmp = basicCat;
    }

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

    Animal  *animals[N];

    for (size_t i = 0; i < N; i++)
    {
        if (i < (N / 2))
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (size_t i = 0; i < N; i++)
    {
        delete animals[i];
    }
}
