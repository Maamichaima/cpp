#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
template <typename t>
void incriment(t& x);

template <typename t, typename f>
void iter(t *x, int size,f func);

#endif