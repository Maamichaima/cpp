#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string Name;
    public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string str);
		DiamondTrap(const DiamondTrap& x);
		DiamondTrap& operator=(const DiamondTrap& other);
		void whoAmI();
};

#endif