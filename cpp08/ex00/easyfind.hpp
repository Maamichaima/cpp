#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &t, int x)
{
    typename T::iterator it = find(t.begin(), t.end(), x);
	if(it == t.end())
		throw(std::runtime_error("Element not found"));
	return it;
}

#endif