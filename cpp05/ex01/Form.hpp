#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int grade;
	public:
		Form();
		~Form();
		std::string getName() const;
		const int getGrade() const;
		bool getisSigned() const;
		const int getgradeToSign() const;
		void GradeTooHighException();
		void GradeTooLowException();
		void beSigned(Bureaucrat&);
};
std::ostream& operator<<(std::ostream& os, const Form& x);

Form::Form(/* args */)
{
}

Form::~Form()
{
}


#endif