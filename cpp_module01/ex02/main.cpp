/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:33 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:34 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>


int main()
{
	std::string sentence = "HI THIS IS BRAIN";

	std::string *stringPTR = &sentence;
	std::string &stringREF = sentence;

    std::cout << &sentence << ": " << sentence << std::endl;
    std::cout << stringPTR << ": " << *stringPTR << std::endl;
    std::cout << &stringREF << ": " << stringREF << std::endl;
}