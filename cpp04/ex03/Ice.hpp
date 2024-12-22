#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Cure.hpp"

class Ice: public AMateria
{   
    public:
        Ice();
        ~Ice();
        Ice(const Ice& c);
        Ice& operator=(const Ice& other);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif