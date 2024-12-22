#include "WrongCat.hpp"
WrongCat::WrongCat()
{
	std::cout << "WrongCat:: Default constructor called\n";
	type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& x)
{
	std::cout << "WrongCat:: copy constructor called \n";
	(*this) = x;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat:: destructor called\n";
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat:: Copy assignment operator called\n";
	if(this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}
void WrongCat::makeSound() const
{
	std::cout << "miaaw \n";
}
