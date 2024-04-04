/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:12 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"


#ifndef FRAGTRAP_H
#define FRAGTRAP_H

class FragTrap : public ClapTrap
{
private:
    
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);

    FragTrap &operator=(const FragTrap& other);
    ~FragTrap();
    void highFivesGuys(void);
};
#endif