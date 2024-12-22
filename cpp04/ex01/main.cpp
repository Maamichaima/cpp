#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	Animal* tab[100];
	int i = 0;
	while(i < 1)/// bedliiiha 
	{
		tab[i] = new Dog();
		i++;
	}
	while(i < 2)
	{
		tab[i] = new Cat();
		i++;
	}
	i = 0;
	while(i < 2)
	{
		delete tab[i];
		i++;
	}
	return 0;
}