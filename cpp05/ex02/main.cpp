#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
int main ()
{
	try
	{
		Bureaucrat b("buree", 5);
		// ShrubberyCreationForm S("lll");
		// b.signForm(S);
		// b.executeForm(S);

		RobotomyRequestForm R("lll");
		b.signForm(R);
		b.executeForm(R);

		// PresidentialPardonForm S("lll");
		// b.signForm(S);
		// b.executeForm(S);
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

