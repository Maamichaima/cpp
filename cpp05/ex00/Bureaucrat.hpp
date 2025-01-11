#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
		class GradeTooHighException : std::exception
		{
			public:
			const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;//noexcept
			// {
			// 	std::cout << "sghiir \n";
			// 	return NULL;
			// }
		};
		class GradeTooLowException : std::exception
		{
			public:
			const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			// {
			// 	std::cout << "kbiiir \n";
			// 	return NULL;
			// }
		};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);

#endif