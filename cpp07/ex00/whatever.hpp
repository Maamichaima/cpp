#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
T max(T x, T y)
{
    if (x > y)
		return x;
	else
		return y;
}
template <typename T>
T min(T x, T y)
{
    if (x < y)
		return x;
	else
		return y;
}
template <typename t>
void swap(t &x, t &y)
{
	t s;

	s = x;
	x = y;
	y = s;
}

#endif