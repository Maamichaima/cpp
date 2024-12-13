#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string str);
		FragTrap(const FragTrap& x);
		FragTrap& operator=(const FragTrap& other);
		void highFivesGuys(void);
};

#endif