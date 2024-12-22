#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain:: Default constructor called\n";
}
Brain::Brain(const Brain& x)
{
	std::cout << "Brain:: copy constructor called \n";
	(*this) = x;
}
Brain::~Brain()
{
	std::cout << "Brain:: destructor called\n";
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain:: Copy assignment operator called\n";
	if(this != &other)
	{
		// this->ideas = other.ideas;// for ??
	}
	return (*this);
}
