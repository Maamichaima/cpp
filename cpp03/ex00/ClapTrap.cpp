#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

}
ClapTrap::ClapTrap(std::string& std)
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
    if(this->Energy_Points >= 1 )//or hit point
    {
        std::cout << "ClapTrap "<< this->Name <<" attacks " << target << ", causing " << this->Attack_Damage << " points of damage!\n" ;
        this->Energy_Points--;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    
}
void ClapTrap::beRepaired(unsigned int amount)
{

}