#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
class AForm;
#include "AForm.hpp"
class Bureaucrat
{
	private:
		const std::string  name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string str, int g);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade() const;
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
		void signForm(AForm&);
		void executeForm(AForm&);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif