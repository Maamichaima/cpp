#include "Point.hpp"

Point::Point(): x(0), y(0){}
Point::Point(const Point &p):x(p.x), y(p.y){}
Point::Point(const Fixed x, const Fixed y):x(x), y(y){}
// Point::Point(Fixed& x, Fixed& y):x(x), y(y){}
Point& Point::operator=(const Point &o) {
    if (this != &o) {
        // Utilisez l'initialisation des membres constants
        // const_cast<Fixed&>(x) = o.x;
        // const_cast<Fixed&>(y) = o.y;
    }
    return *this;
}
Point::~Point()
{

}
const Fixed Point::getX() const
{
    return x;
}
const Fixed Point::getY() const
{
    return y;
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float d1, d2, d3;
    //x1,y1 --> a
    //x2,y2 --> b
    //x3,y3 --> c
    //x,y --> point
    d1 = ((point.getX().getRawBits() - a.getX().getRawBits())) * (b.getY().getRawBits() - a.getY().getRawBits()) - (point.getY().getRawBits() - a.getY().getRawBits()) * (b.getX().getRawBits() - a.getX().getRawBits());
    d2 = ((point.getX().getRawBits() - b.getX().getRawBits())) * (c.getY().getRawBits() - b.getY().getRawBits()) - (point.getY().getRawBits() - b.getY().getRawBits()) * (c.getX().getRawBits() - b.getX().getRawBits());
    d3 = ((point.getX().getRawBits() - c.getX().getRawBits())) * (a.getY().getRawBits() - c.getY().getRawBits()) - (point.getY().getRawBits() - c.getY().getRawBits()) * (a.getX().getRawBits() - c.getX().getRawBits());
    if((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
        return true;
    return false;
}