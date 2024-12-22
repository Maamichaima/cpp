#include "Dog.hpp"
Dog::Dog()
{
	std::cout << "Dog:: Default constructor called\n";
	b = new Brain();
	type = "Dog";
}
Dog::Dog(Dog& x)
{
	std::cout << "Dog:: copy constructor called \n";
	(*this) = x;
}
Dog::~Dog()
{
	delete b;
	std::cout << "Dog:: destructor called\n";
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
		// this->b = other.b;
		this->b = new Brain(*other.b);// deep copy
	}
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "haw haaw\n";
}