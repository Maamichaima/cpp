#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", false, 145,137)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", false, 145,137)
{
	this->target = target;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor)const
{
	AForm::checkExecutionRequirements(executor);
	std::ofstream otf("Shrubbery");
	//is open
	otf << "       ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        |||\\\\//\n        |||||\\\\ \n        |||||\\\\ \n        |||||||||\n  -------------------\n" ;
	//add message of success
}