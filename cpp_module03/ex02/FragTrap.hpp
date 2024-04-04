/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:12 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/04 11:42:03 by evocatur         ###   ########.fr       */
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
    FragTrap(const FragTrap &rhs);

    FragTrap &operator=(const FragTrap& rhs);
    ~FragTrap();
    void highFivesGuys(void);
};
#endif