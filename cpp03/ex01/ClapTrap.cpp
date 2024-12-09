#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

}
ClapTrap::ClapTrap(std::string std)
{
    Name = std;
    Energy_Points = 10;
    Attack_Damage = 0;
    Hit_points = 10;
}
ClapTrap::ClapTrap(const ClapTrap& x)
{
    std::cout << "copy constructor called \n";
    this->operator=(x);
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_Points = other.Energy_Points;
        this->Attack_Damage = other.Attack_Damage;
    }
    return (*this);
}
ClapTrap::~ClapTrap()
{

}
void ClapTrap::attack(const std::string& target)
{
    if(Energy_Points >= 1 && Hit_points >= 1)
    {
        std::cout << "ClapTrap "<< Name <<" attacks " << target << ", causing " << this->Attack_Damage << " points of damage!\n" ;
        Energy_Points--;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(Hit_points >= 1)
    {
		std::cout << "ClapTrap " << Name << " take damage itself, regaining " << amount << " hit points!\n";
		if(amount <= Hit_points)
			Hit_points -= amount;
		else
			Hit_points = 0;
	}
	else
		std::cout << "hhhhhh\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(Energy_Points >= 1 && Hit_points >= 1)
	{
		std::cout << "ClapTrap " << Name << " repairs itself, regaining " << amount << " hit points!\n";
		Hit_points += amount;
	}
}