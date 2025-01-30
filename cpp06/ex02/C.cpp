#include "C.hpp"

C::C()
{
}
C::C(const C &other)
{
	(*this) = other;
}
C &C::operator=(const C &other)
{
	if(&other != this)
	{

	}
	return (*this);
}
C::~C()
{
}