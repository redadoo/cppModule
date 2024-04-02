/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:06:21 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/02 12:54:59 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Brain.hpp"

Brain::Brain()
{
    
}

Brain::Brain( const Brain& src )
{
    *this = src;
}

Brain&   Brain::operator=( const Brain& rhs ) {
    if (this != &rhs) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
	return *this;
}

Brain::~Brain()
{
    
}