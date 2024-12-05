
#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
Zombie::Zombie(std::string str)
{
    name = str;
}
Zombie::~Zombie()
{
    std::cout << "the Zombie " << name << " is destroyed" << std::endl;
}
