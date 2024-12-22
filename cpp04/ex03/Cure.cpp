#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{

}
Cure::~Cure()
{
    
}
Cure::Cure(const Cure &c)
{
    (*this) = c;
}
Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}
AMateria* Cure::clone() const
{
	Cure *c = new Cure();
	return c;
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}