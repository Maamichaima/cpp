#include"ScalarConverter.hpp"

// std::string ScalarConverter::input;


int isInt(std::string str)
{
	int i = 0;

	if(str[i] == '-' || str[i] == '+')
		i++;
	if(!str[i])
		return 0;
	while(str[i])
	{
		if(!isnumber(str[i]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int countChar(std::string str, char c)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(str[i] == c)
			count ++;
		i++;
	}
	return count;
}
int isFloat(std::string str)
{
	int i = 0;
	if(str[i] == '-' || str[i] == '+')
		i++;
	if(!str[i])
		return 0;
	while(str[i])
	{
		if(!isnumber(str[i]) && str[i] != '.' && str[i] != 'f')
		{
			return 0;
		}
		i++;
	}
	if(countChar(str, '.') != 1 || countChar(str, 'f') != 1)
		return 0;
	if(str[i - 1] && str[i - 1] != 'f')
		return 0;
	return 1;
}
int isDouble(std::string str)
{
	int i = 0;
	if(str[i] == '-' || str[i] == '+')
		i++;
	if(!str[i])
		return 0;
	while(str[i])
	{
		if(!isnumber(str[i]) && str[i] != '.')
		{
			return 0;
		}
		i++;
	}
	if(countChar(str, '.') != 1)
		return 0;
	return 1;
}

int isChar(std::string c)
{
	if(c.length() != 1)
		return 0;
	if(!isascii(c[0]))
		return 0;
	return 1;
}

void ScalarConverter::toInt()
{
	flage f = inisialse_();
	ScalarConverter::type = "int";
	double d = atof(ScalarConverter::input.c_str());
	if(d <= INT_MAX && d >= INT_MIN)
		ScalarConverter::_int = atoi(ScalarConverter::input.c_str());
	else
		f.intFlage = 1;
	if(f.intFlage == 0 && d > std::numeric_limits<float>::lowest() && d < std::numeric_limits<float>::max())
		ScalarConverter::_float = static_cast<float>(d);
	else
		f.floatFlage = 1;
	if(f.intFlage == 0 && isascii(ScalarConverter::_int))
		ScalarConverter::_char = static_cast<int>(d);
	else
		f.charFlage = 1;
	if(f.intFlage == 0)
		ScalarConverter::_double = d;
	else
		f.doubleFlage = 1;
	ScalarConverter::display_all(f);
}

void ScalarConverter::toChar()
{
	flage f = inisialse_();
	ScalarConverter::type = "char";
	// double d = atof(ScalarConverter::input.c_str());
	if(isascii(ScalarConverter::input[0]))
		ScalarConverter::_char = static_cast<char>(ScalarConverter::input[0]);
	else
		f.charFlage = 1;
	if(f.charFlage == 0)
		ScalarConverter::_int = static_cast<int>(ScalarConverter::input.c_str()[0]);
	else
		f.intFlage = 1;
	if(f.charFlage == 0)
		ScalarConverter::_float = static_cast<float>(ScalarConverter::input.c_str()[0]);
	else
		f.floatFlage = 1;
	if(f.charFlage == 0)
		ScalarConverter::_double = static_cast<double>(ScalarConverter::input.c_str()[0]);
	else
		f.doubleFlage = 1;
	ScalarConverter::display_all(f);
}

void ScalarConverter::toFloat()
{
	flage f = inisialse_();
	ScalarConverter::type = "float";
	double d = atof(ScalarConverter::input.c_str());
	if(d > std::numeric_limits<float>::lowest() && d < std::numeric_limits<float>::max())
		ScalarConverter::_float = static_cast<float>(d);
	else
		f.floatFlage = 1;
	if(f.floatFlage == 0 && d <= INT_MAX && d >= INT_MIN)
		ScalarConverter::_int = atoi(ScalarConverter::input.c_str());
	else
		f.intFlage = 1;
	if(f.intFlage == 0 && f.floatFlage == 0 && isascii(ScalarConverter::_int))
		ScalarConverter::_char = ScalarConverter::input[0];
	else
		f.charFlage = 1;
	if(f.floatFlage == 0)
		ScalarConverter::_double = d;
	else
		f.doubleFlage = 1;
	ScalarConverter::display_all(f);
}

void ScalarConverter::toDouble()
{
	flage f = inisialse_();
	ScalarConverter::type = "double";
	double d = atof(ScalarConverter::input.c_str());
	ScalarConverter::_double = d;
	if(d > std::numeric_limits<float>::lowest() && d < std::numeric_limits<float>::max())
		ScalarConverter::_float = static_cast<float>(d);
	else
		f.floatFlage = 1;
	if(f.floatFlage == 0 && d <= INT_MAX && d >= INT_MIN)
		ScalarConverter::_int = static_cast<int>(d);
	else
		f.intFlage = 1;
	if(f.intFlage == 0 && isascii(ScalarConverter::_int))
		ScalarConverter::_char = static_cast<char>(d);
	else
		f.charFlage = 1;
	ScalarConverter::display_all(f);
}

void ScalarConverter::display_all(flage f)
{
	if(!f.charFlage)
		std::cout << "char : " << ScalarConverter::_char << "\n";
	else
		std::cout << "char : imposible\n";
	if(!f.intFlage)
		std::cout << "int : " << ScalarConverter::_int << "\n";
	else
		std::cout << "int : imposible\n";
	if(!f.floatFlage)
		std::cout << "float : " << ScalarConverter::_float << ".0f\n";
	else
		std::cout << "float : imposible\n";
	if(!f.doubleFlage)
		std::cout << "double : " << ScalarConverter::_double << ".0\n";
	else
		std::cout << "double : imposible\n";
}

flage inisialse_()
{
	flage f;
	f.charFlage = 0;
	f.intFlage = 0;
	f.floatFlage = 0;
	f.doubleFlage = 0;
	return f;
}