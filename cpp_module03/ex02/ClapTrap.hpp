/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:54 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 11:41:55 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<string>
#include<iostream>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap
{
    protected:
        int         hitPoint;
        int         energyPoints;
        int         attackDamage;

    public:
        std::string name;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getAttackDamage();
        const std::string getName();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &rhs);

        ClapTrap &operator=(const ClapTrap& rhs);
        ~ClapTrap();
};

#endif