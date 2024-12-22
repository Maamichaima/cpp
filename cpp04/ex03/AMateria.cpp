#include "AMateria.hpp"

AMateria::AMateria()
{
    
}
AMateria::~AMateria()
{
    
}
AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
	return(*this);
}
AMateria::AMateria(std::string const & type)
{
    this->type = type;
}
std::string const & AMateria::getType() const
{
    return type;
}
void AMateria::use(ICharacter& target)
{
    (void) target;
}