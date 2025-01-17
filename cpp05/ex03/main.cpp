#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
int main ()
{
	try
	{
		Intern i;
		i.makeForm("PresidentialPardonForm", "target");
		// Bureaucrat b("nn", 1);
		// ShrubberyCreationForm S("lll");
		// b.signForm(S);
		// b.executeForm(S);
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}