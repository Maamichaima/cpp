#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA
{
    private:
        std::string name;
        Weapon& W_A;
    public:
        HumanA(std::string n, Weapon& W);
        void attack(void);
};

#endif
