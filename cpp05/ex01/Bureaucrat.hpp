#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string  name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string str);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade() const;
		void GradeTooHighException();
		void GradeTooLowException();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif