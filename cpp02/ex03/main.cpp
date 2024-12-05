#include "Point.hpp"

int main( void )
{
    Point a(Fixed(1), Fixed(1));
    Point b(Fixed(5), Fixed(1));
    Point c(Fixed(3), Fixed(4));
    Point point(Fixed(1), Fixed(1));
    if(bsp(a, b, c, point) == true)
        std::cout << "daakhlaa\n";
    else
        std::cout << " kharjaaa\n";
    return 0;
}

// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
