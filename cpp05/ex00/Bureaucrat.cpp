#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("hhhhh")
{
}
Bureaucrat::Bureaucrat(std::string str, int g): name(str), grade(g)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << " goood \n";
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
std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}
// void Bureaucrat::GradeTooHighException()
// {
// 	std::cout << "sghiiir \n";
// }
// void Bureaucrat::GradeTooLowException()
// {
// 	std::cout << "kbiir \n";
// }
const char* Bureaucrat::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	std::cout << "sghir \n";
	return NULL;
}
const char* Bureaucrat::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	std::cout << "kbiiir \n";
	return NULL;
}

