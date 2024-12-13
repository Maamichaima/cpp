#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap:: Default constructor called\n";
}
ScavTrap::ScavTrap(std::string str):ClapTrap(str)
{
    // Name = str;//hyeed
    Hit_points = 100;
    Energy_Points = 50;
    Attack_Damage = 20;
    std::cout << "ScavTrap:: constructor parameters\n";
}
ScavTrap::ScavTrap(const ScavTrap& x)
{
    std::cout << "ScavTrap:: copy constructor called\n";
    (*this) = x;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap:: destructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap:: Copy assignment operator called\n";
    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_Points = other.Energy_Points;
        this->Attack_Damage = other.Attack_Damage;
    }
    return (*this);
}
void ScavTrap::attack(const std::string& target)
{
    if(Energy_Points >= 1 && Hit_points >= 1)
    {
        std::cout << "ScavTrap "<< Name <<" attacks " << target << ", causing " << this->Attack_Damage << " points of damage!\n" ;
        Energy_Points--;
    }
    else
    {
        if (Hit_points < 1)
            std::cout << "ScavTrap " << Name << " can't attack because it has no hit points!\n";
        else if (Energy_Points < 1)
            std::cout << "ScavTrap " << Name << " can't attack because it has no energy points!\n";
    }
}
void ScavTrap::guardGate()
{
    std::cout << "Gate keeper mode\n";
}
