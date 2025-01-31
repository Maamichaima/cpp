#ifndef BASE_HPP
#define BASE_HPP

#include<cstdlib>
#include<ctime>
#include<iostream>

class Base
{	
	public:
		Base();
		Base(const Base& other);
		Base& operator=(const Base& other);
		virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif