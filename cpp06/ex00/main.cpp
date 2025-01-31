#include "ScalarConverter.hpp"

std::string ScalarConverter::type;
std::string ScalarConverter::input;
char ScalarConverter::_char;
int ScalarConverter::_int;
double ScalarConverter::_double;
float ScalarConverter::_float;

int main(int ac, char **av)
{
	if(ac < 2)
		return 1;
	ScalarConverter::input = av[1];
	if(isChar(ScalarConverter::input))
		ScalarConverter::toChar();
	else if(isInt(ScalarConverter::input))
		ScalarConverter::toInt();
	else if(isFloat(ScalarConverter::input))
		ScalarConverter::toFloat();
	else if(isDouble(ScalarConverter::input))
		ScalarConverter::toDouble();
	else if(ScalarConverter::input == "nan" || ScalarConverter::input == "nanf")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
	else if(ScalarConverter::input == "+inff" || ScalarConverter::input == "inff")
		std::cout << "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n";
	else if(ScalarConverter::input == "+inf" || ScalarConverter::input == "inf")
		std::cout << "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n";
	else if(ScalarConverter::input == "-inff")
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
	else if(ScalarConverter::input == "-inf")
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
	else
		std::cout << "errrrrrooor\n";
}
