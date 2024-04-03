/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:01 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:02 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef HARL_H
#define HARL_H

#define N 4

class Harl
{
    typedef void (Harl::*t_comments) (void);
    
    private:
        t_comments comm[N];
        
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public:
        Harl();
        ~Harl();
       void complain( std::string level );
};


#endif

