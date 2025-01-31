#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string_view>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <sstream> 
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
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static std::string type;
		static std::string input;
		static char		_char;
		static int		_int;
		static float	_float;
		static double	_double;
		static void toInt();
		static void toChar();
		static void toFloat();
		static void toDouble();
		static void display_all(flage f);
};
int isInt(std::string str);
int countChar(std::string str, char c);
int isFloat(std::string str);
int isDouble(std::string str);
int isChar(std::string c);
#endif