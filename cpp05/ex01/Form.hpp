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
		const int gradeToExecute;
	public:
		Form();
		Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);
		std::string getName() const;
		int getGradeToExecute() const;
		bool getisSigned() const;
		int getgradeToSign() const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const  throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		void beSigned(Bureaucrat &x);
};
std::ostream& operator<<(std::ostream& os, const Form& x);

#endif