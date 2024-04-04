/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:31 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/04 12:23:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0)
	{
		std::cout << this->name <<" attacks, " << target << " lose "<< this->attackDamage <<" Hit points!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		std::cout << this->name << " attack "<< target <<" but has no Energy points left "<< std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " lose "<< this->attackDamage << " hit point "<< std::endl;
	if (this->hitPoint > 0)
		this->hitPoint -= amount;
	else 
		std::cout << this->name << " is dead "<< std::endl;
}

void ClapTrap:: beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << this->name << " is repairing himself for " << amount << " hit point "<< std::endl;
		this->energyPoints--;
		this->hitPoint += amount;
	}
	else
	{
		std::cout << this->name << " repair himself but has no Energy points left "<< std::endl;
	}
}

const std::string ClapTrap::getName()
{
	return this->name;
}

int ClapTrap::getAttackDamage()
{
	return this->attackDamage;
}

ClapTrap::ClapTrap(std::string _name) :name(_name) {
	std::cout << "Initializate ClapTrap :" << this->name << std::endl;
	this->energyPoints = 50;
	this->hitPoint = 100;
	this->attackDamage = 20;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& other ) {
    this->name = other.name;
    this->hitPoint = other.hitPoint;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destroy ClapTrap :"<< this->name << std::endl;
}