#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        _templates[i] = NULL;
    }
}
void MateriaSource::learnMateria(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
        if(_templates[i] == NULL)
		{
            _templates[i] = m;
			break ;
		}
    }
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4; i++)
    {
        if(_templates[i]->getType() == type)
		{
            return _templates[i]->clone();
		}
    }
    return NULL;
}
MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if(_templates[i])
		{
			delete _templates[i];
		}
	}
}
MateriaSource::MateriaSource(const MateriaSource& x)
{
	(*this) = x;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for(int i = 0; i < 4; i++)
		{
			this->_templates[i] = other._templates[i]->clone();
		}
	}
	return (*this);
}
