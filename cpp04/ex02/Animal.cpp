#include "Animal.hpp"
Animal::Animal()
{
	std::cout << "Animal:: Default constructor called\n";
	type = "";
}
Animal::Animal(Animal& x)
{
	std::cout << "Animal:: copy constructor called \n";
	(*this) = x;
}
Animal::~Animal()
{
	std::cout << "Animal:: destructor called\n";
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return type;
}

