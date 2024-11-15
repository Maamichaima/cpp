#include "Contact.hpp"

std:: string Contact:: getFirstName()
{
	return first_name;
}

std:: string Contact:: getlastName()
{
	return last_name;
}

std:: string Contact:: getNickName()
{
	return nickname;
}

std:: string Contact:: getNumber()
{
	return number;
}

std:: string Contact:: getDarkset_secre()
{
	return darkest_secre;
}

void Contact:: setFirstName(std:: string str)
{
	first_name = str;
}

void Contact:: setLastName(std:: string str)
{
	last_name = str;
}

void Contact:: setNickName(std:: string str)
{
	nickname = str;
}

void Contact:: setNumber(std:: string str)
{
	number = str;
}

void Contact:: setDarkset_secre(std:: string str)
{
	darkest_secre = str;
}
