#include "Zombie.hpp"

void Zombie:: announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
Zombie:: Zombie(std::string str)
{
    name = str;
}
Zombie:: Zombie()
{
    std::cout << "the zombie is created" << std::endl;
}
Zombie:: ~Zombie()
{
    std::cout << "the Zombie " << name << " is destroyed" << std::endl;
}
void Zombie:: setZombie(std::string str)
{
    name = str;
}