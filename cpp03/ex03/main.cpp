#include "DiamondTrap.hpp"
int main()
{
	DiamondTrap D("DIAMOND");
	D.display_data();
	D.attack("ATTACK_1");
	D.display_data();
	D.beRepaired(20);
	D.display_data();
	D.takeDamage(60);
	D.display_data();
	D.attack("ATTACK_2");
	D.display_data();
	D.whoAmI();
}
