#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("nn", 1);
		b.incrementGrade();
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return 0;
}

