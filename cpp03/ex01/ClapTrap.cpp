#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap:: Default constructor called\n";
}
ClapTrap::ClapTrap(std::string std)
{
    std::cout << "ClapTrap:: constructor parameters\n";
    Name = std;
    Energy_Points = 100;
    Attack_Damage = 50;
    Hit_points = 20;
}
ClapTrap::ClapTrap(const ClapTrap& x)
{
    std::cout << "ClapTrap:: copy constructor called\n";
    this->operator=(x);
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap:: Copy assignment operator called\n";
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
    std::cout << "ClapTrap:: destructor called\n";
}
void ClapTrap::attack(const std::string& target)
{
    if(Energy_Points >= 1 && Hit_points >= 1)
    {
        std::cout << "ClapTrap "<< Name <<" attacks " << target << ", causing " << this->Attack_Damage << " points of damage!\n" ;
        Energy_Points--;
    }
    else
    {
        if (Hit_points < 1)
            std::cout << "ClapTrap " << Name << " can't attack because it has no hit points!\n";
        else if (Energy_Points < 1)
            std::cout << "ClapTrap " << Name << " can't attack because it has no energy points!\n";
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
        std::cout << "ClapTrap " << Name << " cannot take more damage because it has no hit points!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(Energy_Points >= 1 && Hit_points >= 1)
	{
		std::cout << "ClapTrap " << Name << " repairs itself, regaining " << amount << " hit points!\n";
		Hit_points += amount;
	}
    else
		std::cout << "ClapTrap " << Name << " can't repair itself and remains damaged.\n";
}