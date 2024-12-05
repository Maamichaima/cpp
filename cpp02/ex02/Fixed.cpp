#include "Fixed.hpp"

const int Fixed:: fractional_bits = 8;

Fixed::Fixed()
{
    fixed_point = 0;
    // std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& x)
{
    // std::cout << "Copy constructor called\n";
    fixed_point = x.getRawBits();
}

Fixed::Fixed(const int x)
{
    // std::cout << "Int constructor called" <<std::endl;
    fixed_point = x * (1 << fractional_bits);
}
Fixed::Fixed(const float x)
{
    // std::cout << "Float constructor called" <<std::endl;
    fixed_point = roundf(x * (1 << fractional_bits));
}
Fixed& Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixed_point = other.fixed_point;
    }
    return *this;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
    return fixed_point;
}
void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}
Fixed::~Fixed()
{
    // std::cout <<"Destructor called\n";
}

float Fixed::toFloat( void ) const
{
    float tmp;

    tmp = 1 << fractional_bits;
    return fixed_point / tmp;
}
int Fixed::toInt( void ) const
{
    return fixed_point / (1 << fractional_bits);
}
std::ostream& operator<<(std::ostream& os, const Fixed& x)
{
    os << x.toFloat();
    return os;
}
Fixed Fixed::operator*(const Fixed &o)
{
    Fixed x;
    x.fixed_point = (this->toFloat() * o.toFloat()) * (1 << x.fractional_bits);
    return x;
}
Fixed Fixed::operator+(const Fixed &o)
{
    Fixed x;
    x.fixed_point = (this->toFloat() + o.toFloat()) * (1 << x.fractional_bits);
    return x;
}
Fixed Fixed::operator-(const Fixed &o)
{
    Fixed x;
    x.fixed_point = (this->toFloat() - o.toFloat()) * (1 << x.fractional_bits);
    return x;
}
Fixed Fixed::operator/(const Fixed &o)
{
    Fixed x;
    if (o.fixed_point != 0)
        x.fixed_point = (this->toFloat() / o.toFloat()) * (1 << x.fractional_bits);
    return x;
}
Fixed &Fixed::operator++()
{
    this->fixed_point++;
    return (*this);
}

Fixed Fixed::operator++(int c)
{
    Fixed tmp(*this);
    this->fixed_point++;
    return (tmp);
}
Fixed &Fixed::operator--()
{
    this->fixed_point--;
    return (*this);
}
Fixed Fixed::operator--(int c)
{
    Fixed tmp(*this);
    this->fixed_point--;
    return (tmp);
}
const Fixed& Fixed::max(const Fixed& x, const Fixed& y) 
{
    if(x.getRawBits() > y.getRawBits())
        return (x);
    else
        return (y);
}
Fixed& Fixed::max( Fixed& x,  Fixed& y) 
{
    if(x.getRawBits() > y.getRawBits())
        return (x);
    else
        return (y);
}
const Fixed& Fixed::min(const Fixed& x, const Fixed& y) 
{
    if(x.getRawBits() < y.getRawBits())
        return (x);
    else
        return (y);
}
Fixed& Fixed::min( Fixed& x,  Fixed& y) 
{
    if(x.getRawBits() < y.getRawBits())
        return (x);
    else
        return (y);
}
int Fixed::operator<(const Fixed &o)
{
    if(this->fixed_point < o.fixed_point)
        return 1;
    return 0;
}
int Fixed::operator>(const Fixed &o)
{
    if(this->fixed_point > o.fixed_point)
        return 1;
    return 0;
}
int Fixed::operator<=(const Fixed &o)
{
    if(this->fixed_point <= o.fixed_point)
        return 1;
    return 0;
}
int Fixed::operator>=(const Fixed &o)
{
    if(this->fixed_point >= o.fixed_point)
        return 1;
    return 0;
}
int Fixed::operator==(const Fixed &o)
{
    if(this->fixed_point == o.fixed_point)
        return 1;
    return 0;
}
int Fixed::operator!=(const Fixed &o)
{
    if(this->fixed_point != o.fixed_point)
        return 1;
    return 0;
}