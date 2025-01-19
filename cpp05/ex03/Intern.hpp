#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        
    public:
        Intern();
        ~Intern();
        Intern(const Intern& x);
		Intern& operator=(const Intern& x);
        AForm *makeForm(std::string formName, std::string target);
};
struct FormPair
{
    std::string name;
    AForm* (*createInst)(const std::string);
};
AForm *creatShrubbery(const std::string target);
AForm *creatPresidential(const std::string target);
AForm *creatRobotomy(const std::string target);

#endif