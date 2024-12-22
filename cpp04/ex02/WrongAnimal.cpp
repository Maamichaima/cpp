#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal:: Default constructor called\n";
	type = "";
}
WrongAnimal::WrongAnimal(WrongAnimal& x)
{
	std::cout << "WrongAnimal:: copy constructor called \n";
	(*this) = x;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal:: destructor called\n";
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal:: Copy assignment operator called\n";
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "pcha9 pcha9\n";
}
