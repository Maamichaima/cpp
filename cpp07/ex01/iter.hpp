#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename t, typename f>
void iter(t *x, int size,f func)
{
	for(int i = 0; i < size; i++)
	{
		func(x[i]);
	}	
}

#endif