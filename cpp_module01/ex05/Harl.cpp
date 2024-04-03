/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:34 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 13:50:45 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::debug( void ) {
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}


Harl::Harl() 
{
    comm[0] = &Harl::error;
    comm[1] = &Harl::info;
    comm[2] = &Harl::warning;
    comm[3] = &Harl::debug;
}

Harl::~Harl() {}

void    Harl::complain( std:: string level ) {
    size_t      index;

    std::string levels[] = { "ERROR", "INFO", "WARNING", "DEBUG"};
    for(index = 0 ; index < N && level != levels[index]; index++) {}
    switch ( index )
    {
        case 0:
            (this->*comm[index])();
            break;
        case 1:
            (this->*comm[index])();
            break;
        case 2:
            (this->*comm[index])();
            break;
        case 3:
            (this->*comm[index])();
            break;
    }
}