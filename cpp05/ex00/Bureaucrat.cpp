#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("bureee"), grade(150)
{
}
Bureaucrat::Bureaucrat(std::string str, int g): name(str), grade(g)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "The Bureaucrat class has been successfully created ✅.\n";
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	(*this) = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
	{
		this->grade = other.grade;
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
	grade--;
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade()
{
	grade++;
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
const std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "too low ⬇️ ";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return  "too high ⬆️ ";
}

