#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <cstdlib> 
#include "AForm.hpp"
class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& x);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& x);
		~RobotomyRequestForm();
		void execute(const Bureaucrat& executor)const;
};										

#endif