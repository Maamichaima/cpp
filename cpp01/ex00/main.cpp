#include "Zombie.hpp"

int main ()
{
    Zombie* obj1 = newZombie("heap");
    obj1->announce();
    randomChump("stack");
    delete obj1;
}