#include "Form.hpp"

// Form::Form()
// {
// }
Form::Form(std::string name, bool isSigned, int gradeToSign, int grade): name(name), isSigned(isSigned), gradeToSign(gradeToSign), grade(grade)
{
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	std::cout << "sghir \n";
	return NULL;
}
const char* Form::GradeTooLowException::what() const throw()
{
	std::cout << "kbiiir \n";
	return NULL;
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

int Form::getGrade() const
{
    return grade;
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
	os << x.getName() << ", bureaucrat grade " << x.getGrade();
	os << ", isSigned --> " << x.getisSigned() << ", gradeToSigne -->" << x.getgradeToSign() << std::endl;
	return os;
}