#include "Zombie.hpp"

int main()
{
    Zombie* t;
    int N;

    N = 4;
    t = zombieHorde(N, "zzombie");
    if(!t)
        return 1;
    for(int i = 0; i < N; i++)
    {
        t[i].announce();
    }
    delete[] t;
    return 0;
}
