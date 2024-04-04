/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<string>
#include<iostream>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap
{
    private:
        std::string name;
        int         hitPoint;
        int         energyPoints;
        int         attackDamage;

    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getAttackDamage();
        const std::string getName();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);

        ClapTrap &operator=(const ClapTrap& other);
        
        ~ClapTrap();
};

#endif