#include "AForm.hpp"

AForm::AForm():name(""), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}
AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}
AForm::AForm(const AForm &other):name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}
AForm::~AForm()
{
}
AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return "too low ⬇️ ";
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return  "too high ⬆️ ";
}
void AForm::beSigned(Bureaucrat &x)
{
	if(x.getGrade() <= gradeToSign)
	{
		isSigned = true;
	}
	else
		throw(AForm::GradeTooLowException());
}
std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}
bool AForm::getisSigned() const
{
	return isSigned;
}
int AForm::getgradeToSign() const
{
	return gradeToSign;
}
std::ostream& operator<<(std::ostream& os, const AForm& x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGradeToExecute();
	os << ", isSigned --> " << x.getisSigned() << ", gradeToSigne -->" << x.getgradeToSign() << std::endl;
	return os;
}
void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (!isSigned)
	{
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute)
	{
        throw GradeTooLowException();
    }
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}
