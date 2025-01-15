#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class RobotomyRequestForm: AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm();
		~RobotomyRequestForm();
		void execute(const Bureaucrat& executor)const;
};										

#endif