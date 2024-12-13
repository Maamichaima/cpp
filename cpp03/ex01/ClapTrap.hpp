#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string Name;
        unsigned int Hit_points;
        unsigned int Energy_Points;
        unsigned int Attack_Damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& x);
        ClapTrap(std::string std);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void display_data();
};

#endif