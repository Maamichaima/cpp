#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
	FragTrap f("FRAG");
	f.display_data();
	f.attack("FF");
	f.display_data();
    f.beRepaired(101);
	f.display_data();
    f.takeDamage(201);
	f.display_data();
    f.takeDamage(3);
	f.highFivesGuys();
	f.display_data();
}
