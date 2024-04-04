/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:06:21 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
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

Brain&   Brain::operator=( const Brain& other ) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
	return *this;
}

Brain::~Brain()
{
    
}