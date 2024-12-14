#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap:: Default constructor called\n";
    this->Hit_points = FragTrap::Hit_points;
    this->Energy_Points = ScavTrap::Energy_Points;
    this->Attack_Damage = FragTrap::Attack_Damage;
}
DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap:: constructor parameters\n";
    this->Name = name;
    this->Hit_points = FragTrap::Hit_points;
    this->Energy_Points = ScavTrap::Energy_Points;
    this->Attack_Damage = FragTrap::Attack_Damage;
}
DiamondTrap::DiamondTrap(const DiamondTrap& x)
{
    std::cout << "DiamondTrap:: copy constructor called\n";
    (*this) = x;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap:: destructor called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap:: Copy assignment operator called\n";
    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_Points = other.Energy_Points;
        this->Attack_Damage = other.Attack_Damage;
    }
    return (*this);
}
void DiamondTrap::whoAmI()
{
    std::cout << "Name of DiamondTrap --> " << this->Name << std::endl;
    std::cout << "Name of ClapTrap -----> " << ClapTrap::Name << std::endl;
}