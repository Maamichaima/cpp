#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", false, 145,137)
{
	this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", false, 145,137)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
	AForm::checkExecutionRequirements(executor);
	//seed
	if (rand() % 2 == 0) {
        std::cout << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy failed!" << std::endl;
    }
}