#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string Name;
        int Hit_points;
        int Energy_Points;
        int Attack_Damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& x);
        ClapTrap(std::string& std);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif