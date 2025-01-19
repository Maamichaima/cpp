#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
int main ()
{
	try
	{
		AForm *x;
		Intern i;
		x = i.makeForm("ShrubberyCreationForm", "target");
		delete (x);
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}