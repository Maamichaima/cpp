#include "A.hpp"

A::A()
{
}
A::A(const A &other)
{
	(*this) = other;
}
A &A::operator=(const A &other)
{
	if(&other != this)
	{

	}
	return (*this);
}
A::~A()
{
}