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
	std::cout << "Initializate ClapTrap :" << this->name << std::endl;
	this->energyPoints = 100;
	this->hitPoint = 100;
	this->attackDamage = 30;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destroy ClapTrap :"<< this->name << std::endl;
}