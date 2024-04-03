/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:38:59 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:38:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() 
{

    std::string input;
    Harl        harl;

    while (1)
    {
        std::cin >> input;
        harl.complain(input);
        if(input.compare("exit") == 0)
            break;
    }

    return 0;
}