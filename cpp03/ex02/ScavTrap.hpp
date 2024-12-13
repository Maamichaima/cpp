#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap// 3lach public
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const ScavTrap& x);
		ScavTrap& operator=(const ScavTrap& other);
		void attack(const std::string& target);
		void guardGate();// const;
};

#endif