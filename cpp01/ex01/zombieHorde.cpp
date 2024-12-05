#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;
    if (N < 1)
    {
        std::cout << N << " is not a valide integer\n";
        return NULL;
    }
    Zombie* tab = new Zombie[N];
    for(i = 0; i < N; i++)
    {
        tab[i].setZombie(name);
    }
    return tab;
}