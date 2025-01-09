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
		Bureaucrat(std::string str, int g);
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
// Bureaucrat::Bureaucrat  ():name(" ")
// {
// }
// Bureaucrat::Bureaucrat(std::string str): name(str)
// {
// 	grade = rand();
// 	try
// 	{
// 		if(grade < 1 || grade > 150)
// 			throw (grade);
// 		else 
// 			std::cout << " goood \n";
// 	}
// 	catch(int grade)
// 	{
// 		if(grade < 1)
// 			GradeTooHighException();
// 		else
// 			GradeTooLowException();
// 	}
// }
// Bureaucrat::~Bureaucrat()
// {
// }
// Bureaucrat::Bureaucrat(Bureaucrat& const other)
// {

// }
// Bureaucrat& Bureaucrat::operator=(Bureaucrat& const other)
// {

// }
// void Bureaucrat::incrementGrade()
// {
// 	try
// 	{
// 		grade--;
// 		if(grade < 1)
// 			throw grade;
// 	}
// 	catch(int grade)
// 	{
// 		if(grade < 1)
// 			GradeTooHighException();
// 	}
// }
// void Bureaucrat::decrementGrade()
// {
// 	try
// 	{
// 		grade++;
// 		if(grade > 150)
// 			throw grade;
// 	}
// 	catch(int grade)
// 	{
// 		if(grade > 150)
// 			GradeTooLowException();
// 	}
// }

#endif