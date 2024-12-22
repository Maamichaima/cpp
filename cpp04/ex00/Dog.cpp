#include "Dog.hpp"
Dog::Dog()
{
	std::cout << "Dog:: Default constructor called\n";
	type = "Dog";
}
Dog::Dog(const Dog& x)
{
	std::cout << "Dog:: copy constructor called \n";
	(*this) = x;
}
Dog::~Dog()
{
	std::cout << "Dog:: destructor called\n";
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "haw haaw\n";
}