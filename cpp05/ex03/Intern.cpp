#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}
AForm *creatShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm *creatPresidential(const std::string target)
{
    return (new PresidentialPardonForm(target));---
}
AForm *creatRobotomy(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    FormPair f[3] = {{"ShrubberyCreationForm", &creatShrubbery}, {"PresidentialPardonForm", &creatPresidential}, {"RobotomyRequestForm", &creatRobotomy}};
    for(int i = 0; i < 3; i++)
    {
        // std::cout << target << " " << f[i].name << std::endl;
        if(formName == f[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return f[i].createInst(target);
        }
    }
    std::cout << "the formName is not exixte \n";
    return NULL;
}