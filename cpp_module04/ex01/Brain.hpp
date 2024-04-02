/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:06:18 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/02 12:55:01 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include<iostream>

class Brain
{
private:
    
public:
    std::string ideas[100];
    Brain();
    Brain( const Brain& src );
    Brain& operator=( const Brain& rhs );
    ~Brain();
};


#endif