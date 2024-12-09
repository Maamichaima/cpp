#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("gg");
	a.attack("hadik");
	a.takeDamage(9);
	a.takeDamage(-1);
	a.takeDamage(9);
	// a.beRepaired(5);
}