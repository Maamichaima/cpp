#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("buree", 120);
		Form x("fooorm", false, 130, 10);
		x.beSigned(b);
		std::cout << b << std::endl;
	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return 0;
}
