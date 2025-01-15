#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
int main ()
{
	try
	{
		Bureaucrat b("nn", 1);
		ShrubberyCreationForm S("lll");
		b.signForm(S);
		b.executeForm(S);
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}