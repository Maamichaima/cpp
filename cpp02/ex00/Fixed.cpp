#include "Fixed.hpp"

const int Fixed:: fractional_bits = 8;
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    fixed_point = 0;
}
Fixed::Fixed(const Fixed& x)
{
    std::cout << "Copy constructor called\n";
    fixed_point = x.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixed_point = other.fixed_point;
    }
    return *this;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return fixed_point;
}
void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}
Fixed::~Fixed()
{
    std::cout <<"Destructor called\n";
}
