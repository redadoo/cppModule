/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:20 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/14 15:18:36 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal  *animals[100];

    for (size_t i = 0; i < 100; i++)
    {
        if (i < 50)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (size_t i = 0; i < 100; i++)
    {
        delete animals[i];
    }
}
