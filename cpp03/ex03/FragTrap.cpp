#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap:: Default constructor called 👽\n";
    Hit_points = 100;
    Energy_Points = 100;
    Attack_Damage = 30;
}
FragTrap::FragTrap(std::string str):ClapTrap(str)
{
    std::cout << "FragTrap:: constructor parameters 👽\n";
    Hit_points = 100;
    Energy_Points = 100;
    Attack_Damage = 30;
}
FragTrap::FragTrap(const FragTrap& x)
{
    std::cout << "FragTrap:: copy constructor called 👽\n";
    (*this) = x;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap:: destructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap:: Copy assignment operator called\n";
    if(this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_Points = other.Energy_Points;
        this->Attack_Damage = other.Attack_Damage;
    }
    return (*this);
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "high five positif 🖐\n";
}