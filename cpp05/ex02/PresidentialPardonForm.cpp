#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", false, 25,5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", false, 25,5)
{
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
	AForm::checkExecutionRequirements(executor);
	std::cout << target << " a été gracié par Zaphod Beeblebrox.\n";
}
