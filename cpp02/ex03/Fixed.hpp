#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits;
    public:
        Fixed();
        Fixed(const int x);
        Fixed(const float x);
        Fixed(const Fixed& x);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed operator*(const Fixed &o);
        Fixed operator+(const Fixed &o);
        Fixed operator-(const Fixed &o);
        Fixed operator/(const Fixed &o);
        Fixed operator++();
        Fixed operator++(int c);
        Fixed operator--();
        Fixed operator--(int c);
        int operator<(const Fixed &o);
        int operator>(const Fixed &o);
        int operator<=(const Fixed &o);
        int operator>=(const Fixed &o);
        int operator==(const Fixed &o);
        int operator!=(const Fixed &o);
        // static  Fixed& max( Fixed& x,  Fixed& y);
        static const Fixed& max(const Fixed& x, const Fixed& y);        static  Fixed& max( Fixed& x,  Fixed& y);
        static  Fixed& min( Fixed& x,  Fixed& y);
        static const Fixed& min(const Fixed& x, const Fixed& y);
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif