#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain& x);
		Brain& operator=(const Brain& other);
		~Brain();
};


#endif 