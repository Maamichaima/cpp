#include "Form.hpp"

void Form::GradeTooHighException()
{
	std::cout << "sghiiir \n";
}
void Form::GradeTooLowException()
{
	std::cout << "kbiir \n";
}
void Form::beSigned(Bureaucrat &x)
{
	try
	{
		if(x.getGrade() <= gradeToSign)
			isSigned = true;
		else
			throw(grade);
	}
	catch(int grade)
	{
		GradeTooLowException(); 
	}	
}
std::string Form::getName() const
{
    return name;
}

const int Form::getGrade() const
{
    return grade;
}
bool Form::getisSigned() const
{
	return isSigned;
}
const int Form::getgradeToSign() const
{
	return gradeToSign;
}
std::ostream& operator<<(std::ostream& os, const Form& x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGrade();
	return os;
}