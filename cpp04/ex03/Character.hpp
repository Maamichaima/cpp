#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Lst.hpp"

class Character : public ICharacter
{
    private:
        AMateria* _inventory[4];
        std::string _name;
    public:
        Character();
        Character(const Character& x);
        ~Character();
        Character(std::string n);
        Character& operator=(const Character& other);
        std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif