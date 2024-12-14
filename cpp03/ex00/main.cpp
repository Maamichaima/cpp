#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("CLAP");
	ClapTrap b(a);

	a.display_data();
	a.attack("hadik");
	a.display_data();
	a.takeDamage(11);
	a.display_data();
	a.beRepaired(5);
	a.display_data();
}