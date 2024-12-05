#include "Weapon.hpp"

void Weapon:: setType(std::string str)
{
    type = str;
}

const std::string& Weapon::getType(void) const
{
    return type;
}

Weapon:: Weapon(std::string str)
{
    type = str;
}
