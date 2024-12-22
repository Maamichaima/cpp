#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
}
Ice::~Ice()
{
}
Ice::Ice(const Ice& c)
{
    (*this) = c;
}
Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}
AMateria* Ice::clone() const 
{
	Ice *c = new Ice();
	return c;
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n" ;
}