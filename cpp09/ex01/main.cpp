#include "RPN.hpp"


int main(int c, char **av)
{
	try
	{
		if(c != 2)
			throw std::runtime_error("ERROR");
		std::stack<std::string> arg;
		arg = split(av[1], ' ');
		int result = calcul(arg);
		std::cout << "result --> " << result<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
