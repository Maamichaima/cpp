#include "Point.hpp"

int main( void )
{
    Point a(Fixed(1), Fixed(1));
    Point b(Fixed(5), Fixed(1));
    Point c(Fixed(3), Fixed(4));
    Point point(Fixed(3), Fixed(2));
    if(bsp(a, b, c, point) == true)
        std::cout << "the point is inside triangle ABC \n";
    else
        std::cout << "the point is outside triangle ABC\n";
    return 0;
}