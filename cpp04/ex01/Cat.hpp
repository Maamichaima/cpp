#ifndef CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	Brain *b;
	public:
		Cat();
		Cat(Cat&);
		~Cat();
		Cat& operator=(const Cat& other);
		void makeSound() const;
};

#endif