#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::Base(const Base& other)
{
	(*this) = other;
}

Base &Base::operator=(const Base& other)
{
	(void)other;
	return (*this);
}

Base::~Base()
{
}

Base *generate(void)
{
	srand(time(0));
	int r = rand() % 3;
	Base *b = NULL;
	if(r == 0)
		b = new A();
	else if(r == 1)
		b = new B();
	else if(r == 2)
		b = new C();
	return b;
}

void identify(Base *p)
{
	A* pA;
	B* pB;
	C* pC;

	pA = dynamic_cast<A*>(p);
	pB = dynamic_cast<B*>(p);
	pC = dynamic_cast<C*>(p);
	if(pA)
		std::cout << "A\n";
	else if(pB)
		std::cout << "B\n";
	else if(pC)
		std::cout << "C\n";
}

void identify(Base &p)
{
	A pA;
	B pB;
	C pC;

	try
	{
		pA = dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		pB = dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		pC = dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "n'est existe pas\n";
}
