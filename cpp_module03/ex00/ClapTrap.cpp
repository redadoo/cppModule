#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->energyPoints >0)
	{
		std::cout << this->name <<" attacks " << target << " causing "<< this->attackDamage <<" points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		std::cout << this->name << " tries to attack "<< target <<" but has no energy "<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " take damage  causing  lost "<< this->attackDamage << " hit point "<< std::endl;
	if (this->hitPoint > 0 && this->energyPoints >0)
		this->hitPoint -= amount;
	else 
		delete this;
}

void ClapTrap:: beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->energyPoints >0)
	{
		std::cout << this->name << " is repairing himself for " << amount << " hit point "<< std::endl;
		this->energyPoints--;
		this->hitPoint += amount;
	}
	else
	{
		std::cout << this->name << " tries to repair himself but has no energy "<< std::endl;
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
	std::cout << "Initializate " << this->name << std::endl;
	this->energyPoints = 10;
	this->hitPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    *this = rhs;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& rhs ) {
    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destroy "<< this->name << std::endl;
}