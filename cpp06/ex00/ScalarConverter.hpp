#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

typedef struct s_flage
{
	int intFlage;
	int charFlage;
	int floatFlage;
	int doubleFlage;
}	flage;

flage inisialse_();

class ScalarConverter
{
	private:
		
	public:
		static std::string type;
		static std::string input;
		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		// ScalarConverter();
		// ScalarConverter(std::string str);
		// ScalarConverter(const ScalarConverter& other);
		// ScalarConverter& operator=(const ScalarConverter& other);
		// int checkChar();
		static void toInt();
		static void toChar();
		static void toFloat();
		static void toDouble();
		static void display_all(flage f);
		// ~ScalarConverter();
};
int isInt(std::string str);
int countChar(std::string str, char c);
int isFloat(std::string str);
int isDouble(std::string str);
int isChar(std::string c);

// ScalarConverter::ScalarConverter()
// {
// }

// ScalarConverter::ScalarConverter(std::string str)
// {
// 	input = str;
// 	if(isChar(str))
// 		type = "char";
// 	else if(isInt(str))
// 		type = "int";
// 	else if(isFloat(str))
// 		type = "float";
// 	else if(isDouble(str))
// 		type = "double";
// 	else 
// 		std::cout << "errrrrrooor\n";
	
// }

// ScalarConverter::~ScalarConverter()
// {
// }

// ScalarConverter::ScalarConverter(const ScalarConverter& other)
// {

// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
// {
// 	return (*this);
// }


// int ScalarConverter::checkChar()
// {
// 	int i = 0;
// 	while (input[i])
// 	{
// 		if(input[i] >= 'a' && input[i] <= 'z')
// 		{
// 			//is char 
// 		}
// 		else if(input[i] >= '0' && input[i] <= '9')
// 		{
// 			//is num 
// 		}
// 		// else if()
// 		// {

// 		// }
// 	}
// 	return 1;
// }
#endif