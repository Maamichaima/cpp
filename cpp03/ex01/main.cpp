#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	// ClapTrap a("gg");
	ScavTrap s("hihi");
	s.attack("siif");
    s.beRepaired(101);
    s.beRepaired(100);
	s.guardGate();
	s.takeDamage(200);
	s.takeDamage(200);
	// s.takeDamage(200);
	s.attack("sif");
}
