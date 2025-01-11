#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("nn", 1);
		b.incrementGrade();
	}
	catch(const  Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const  Bureaucrat::GradeTooLowException& f)
	{
		std::cerr << f.what() << '\n';
	}
    return 0;
}

