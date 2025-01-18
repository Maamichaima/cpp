// #include "ShrubberyCreationForm.hpp"
// #include "Bureaucrat.hpp"
// int main ()
// {
// 	try
// 	{
// 		Bureaucrat b("nn", 1);
// 		ShrubberyCreationForm S("lll");
// 		b.signForm(S);
// 		b.executeForm(S);
// 	}
// 	catch(const  std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }
#include <iostream>
#include <stdexcept>

void fonction() {
    throw (5);
}

int main() {
    try {
        fonction();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception générale attrapée : " << e.what() << std::endl;
    }
    return 0;
}
