#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;
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
		Form(std::string name, bool isSigned, int gradeToSign, int grade);
		~Form();
		std::string getName() const;
		int getGrade() const;
		bool getisSigned() const;
		int getgradeToSign() const;
		class GradeTooHighException : std::exception
		{
			public:
			const char* what() const  throw();//noexcept
		};
		class GradeTooLowException : std::exception
		{
			public:
			const char* what() const throw();
		};
		void beSigned(Bureaucrat &x);
};
std::ostream& operator<<(std::ostream& os, const Form& x);

#endif