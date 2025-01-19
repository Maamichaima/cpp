#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.hpp"
class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm();
		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);
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
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		void checkExecutionRequirements(const Bureaucrat& executor) const;
		void beSigned(Bureaucrat &x);
		virtual void execute(const Bureaucrat& executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& x);



#endif