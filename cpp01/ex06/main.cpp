#include "Harl.hpp"

int main (int c, char **v)
{
    Harl h;
    if(c != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    h.complain(v[1]);
    return (0);
}
