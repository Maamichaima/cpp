#include "Cat.hpp"
Cat::Cat()
{
	std::cout << "Cat:: Default constructor called\n";
	b = new Brain();
	type = "Cat";
}
Cat::Cat(Cat& x)
{
	std::cout << "Cat:: copy constructor called \n";
	(*this) = x;
}
Cat::~Cat()
{
	delete b;
	std::cout << "Cat:: destructor called\n";
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
		this->b = new Brain(*other.b);
	}
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "miaaaw \n";
}
