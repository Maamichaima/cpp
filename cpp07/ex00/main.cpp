#include "whatever.hpp"
template <typename T> T max(T x, T y)
{
    if (x >= y)
		return x;
	else
		return y;
}
template <typename T> T min(T x, T y)
{
    if (x <= y)
		return x;
	else
		return y;
}
template <typename t> void swap(t &x, t &y)
{
	t s;

	s = x;
	x = y;
	y = s;
}
int main( void ) {
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}