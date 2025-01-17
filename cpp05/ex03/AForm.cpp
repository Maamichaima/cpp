#include "AForm.hpp"

// AForm::AForm()
// {
// }
AForm::AForm(std::string name, bool isSigned, int gradeToSign, int grade): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(grade)
{
}
AForm::~AForm()
{
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return "sghir \n";
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return "kbiiir \n";
}
void AForm::beSigned(Bureaucrat &x)
{
	if(x.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw(AForm::GradeTooLowException());
}
std::string AForm::getName() const
{
    return name;
}
int AForm::getgradeToExecute() const
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
	os << x.getName() << ", bureaucrat grade " << x.getgradeToExecute();
	os << ", isSigned --> " << x.getisSigned() << ", gradeToSigne -->" << x.getgradeToSign() << std::endl;
	return os;
}
void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (!isSigned) {
		// std::cout << " hhh \n ";
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}
