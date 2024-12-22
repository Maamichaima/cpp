#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	std::cout << wrongcat->getType() << std::endl;
	wrongcat->makeSound();
	wrongmeta->makeSound();
	delete meta;
	delete dog;
	delete cat;
	delete wrongcat;
	delete wrongmeta;
	return 0;
}
