#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("hhhhh")
{
}
Bureaucrat::Bureaucrat(std::string str, int g): name(str), grade(g)
{
	// std::cout << << grade << "\n";
	try
	{
		if(grade < 1 || grade > 150)
			throw (grade);
		else
			std::cout << " goood \n";
	}
	catch(int grade)
	{
		if(grade < 1)
			GradeTooHighException();
		else
			GradeTooLowException();
	}
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	(*this) = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
	{
		this->grade = other.grade;
		// this->name = other.name;
	}
	return (*this);
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGrade();
	return os;
}
void Bureaucrat::incrementGrade()
{
	try
	{
		grade--;
		if(grade < 1)
			throw grade;
	}
	catch(int grade)
	{
		if(grade < 1)
			GradeTooHighException();
	}
}
void Bureaucrat::decrementGrade()
{
	try
	{
		grade++;
		if(grade > 150)
			throw grade;
	}
	catch(int grade)
	{
		if(grade > 150)
			GradeTooLowException();
	}
}
std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}
void Bureaucrat::GradeTooHighException()
{
	std::cout << "sghiiir \n";
}
void Bureaucrat::GradeTooLowException()
{
	std::cout << "kbiir \n";
}