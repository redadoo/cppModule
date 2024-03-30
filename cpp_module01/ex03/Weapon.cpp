#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}


void Weapon::setType(std::string newType)
{
    this->type = newType;
}

const std::string& Weapon::getType()
{
    return this->type;
}