#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string str);
		// ScavTrap(ScavTrap x);
		// ScavTrap& operator=(ScavTrap& other);
		void attack(const std::string& target);
};

#endif