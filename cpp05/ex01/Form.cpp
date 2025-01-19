#include "Form.hpp"

Form::Form():name(""), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}
Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}
Form::Form(const Form &other):name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}
Form::~Form()
{
}
Form &Form::operator=(const Form &other)
{
    if(this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}
const char* Form::GradeTooHighException::what() const throw()
{
	return "too low ⬇️ ";
}
const char* Form::GradeTooLowException::what() const throw()
{
	return "too high ⬆️ ";
}
void Form::beSigned(Bureaucrat &x)
{
	if(x.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw(Form::GradeTooLowException());
}
std::string Form::getName() const
{
    return name;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}
bool Form::getisSigned() const
{
	return isSigned;
}
int Form::getgradeToSign() const
{
	return gradeToSign;
}
std::ostream& operator<<(std::ostream& os, const Form& x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGradeToExecute();
	os << ", isSigned --> " << x.getisSigned() << ", gradeToSigne -->" << x.getgradeToSign() << std::endl;
	return os;
}