#include "iter.hpp"

template <typename t>
void incriment(t& x)
{
	x++;
}

template <typename t, typename f>
void iter(t *x, int size,f func)
{
	for(int i = 0; i < size; i++)
	{
		func(x[i]);
	}	
}

int main()
{
	char tab[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "=========================\n";
	for(int i = 0; i < 5; i++)
	{
		std::cout << tab[i] << "----";
	}
	std::cout << "\n";
	std::cout << "=========================\n";
	iter(tab, 5, incriment<char>);
	for(int i = 0; i < 5; i++)
	{
		std::cout << tab[i] << "----";
	}
	std::cout << "\n";
	std::cout << "=========================\n";
	return 0;
}