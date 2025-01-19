#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm: public AForm
{	
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& x);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& x);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat& executor)const;
};										

#endif