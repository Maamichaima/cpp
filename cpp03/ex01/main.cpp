#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	ScavTrap s("SCAV");
	s.display_data();
	s.attack("FF");
	s.display_data();
    s.beRepaired(101);
	s.display_data();
    s.takeDamage(201);
	s.display_data();
    s.takeDamage(3);
	s.guardGate();
	s.display_data();
}
