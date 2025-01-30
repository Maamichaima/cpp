
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    C a;
    identify(a);

    Base *randomBase = generate();
    identify(randomBase);
    delete randomBase;

    return 0;
}

