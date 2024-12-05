#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
class HumanB
{
    private:
        std::string name;
        Weapon *W_B;
    public:
        void attack(void);
        HumanB(std::string str);
        void setWeapon(Weapon& W);
};

#endif