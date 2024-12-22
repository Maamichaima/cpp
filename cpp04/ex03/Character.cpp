#include "Character.hpp"
#include "Lst.hpp"

Lst l;
Character::Character()
{
    for(int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}
Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
		if (_inventory[i])
        	delete _inventory[i];
    }
}
Character::Character(std::string n)
{
    _name = n;
    for(int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}
Character::Character(const Character& x)
{
	(*this) = x;
}
Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            _inventory[i] = other._inventory[i]->clone();
        }
        _name = other._name;
    }
    return (*this);
}
std::string const & Character::getName() const
{
	return _name;
}
void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if(!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
	}
}
void Character::unequip(int idx)
{
	for(int i = 0; i < 4; i++)
	{
		if(i == idx && _inventory[i] != NULL)
        {
            l.add_back(l.new_lst(_inventory[i]));
            _inventory[i] = NULL;
        }
	}
}
void Character::use(int idx, ICharacter& target)
{
	if(idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
}