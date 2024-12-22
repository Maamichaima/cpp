#include "Cat.hpp"
Cat::Cat()
{
	std::cout << "Cat:: Default constructor called\n";
	type = "Cat";
}
Cat::Cat(const Cat& x)
{
	std::cout << "Cat:: copy constructor called \n";
	(*this) = x;
}
Cat::~Cat()
{
	std::cout << "Cat:: destructor called\n";
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "miaaaw \n";
}
