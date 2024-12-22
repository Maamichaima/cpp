#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	Animal *d = new Dog();
	Animal *c = new Cat();
	d->makeSound();
	c->makeSound();
	delete d;
	delete c;
	return 0;
}