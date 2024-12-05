#include "HumanB.hpp"

void HumanB:: attack()
{
    if(W_B)
        std::cout << name <<  " attacks with their " << W_B->getType() << std::endl;
    else
        std::cout << name <<  " don't have a weapon \n";
}

void HumanB:: setWeapon(Weapon& W)
{
    W_B = &W;
}

HumanB:: HumanB(std::string str)
{
    name = str;
    W_B = NULL;
}
