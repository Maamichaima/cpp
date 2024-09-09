#include "PhoneBook.hpp"
#include "Contact.hpp"
Contact& PhoneBook::getContact(int i)// contact
{
	return tab[i];
}

void PhoneBook::Add_New_Contact()
{
	std::string f_n;
	std::string l_n;
	std::string n_n;
	std::string n;
	
	for(int i = 0; i < 4; i++)
	{
		std::cout << "give me "<< m_error[i] << " : ";
		std::getline(std::cin, att[i]);
		if(att[i].length() == 0)
		{
			std::cout << m_error[i] <<" is not valide\n";
			return;
		}
	}
	if(index == 8)
		index = 0;
	tab[index].setFirstName(att[0]);
	tab[index].setLastName(att[1]);
	tab[index].setNickName(att[2]);
	tab[index].setNumber(att[3]);
	index++;
}

PhoneBook::PhoneBook()
{
	index = 0;
	m_error[0] = "first name";
	m_error[1] = "last name";
	m_error[2] = "nick name";
	m_error[3] = "number";
}

int check_num(std::string index)
{
	for (int i = 0; index[i]; i++)
	{
		if(index[i] < '0' || index[i] > '9')
			return 0;
	}
	return 1;
}

void PhoneBook::search()
{
	int width = 10;
	std::string index;
	std::string firstName, lastName, nickName, num;
	
	std::cout << std::setw(width) << "first name" << "|";
	std::cout << std::setw(width) << "last name" << "|";
	std::cout << std::setw(width) << "nick name" << "|";
	std::cout << std::setw(width) << "number" << "|\n";
	std::cout << "-------------------------------------------|\n";
	for (int i = 0; i <= 7; ++i)
	{
		firstName = getContact(i).getFirstName();
		lastName = getContact(i).getlastName();
		nickName = getContact(i).getNickName();
		num = getContact(i).getNumber();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0,9) + ".";
		if (nickName.length() > 10)
			nickName = nickName.substr(0,9) + ".";
		if (num.length() > 10)
			num = num.substr(0,9) + ".";
		std::cout << std::setw(width) << firstName << "|";
		std::cout << std::setw(width) << lastName << "|";
		std::cout << std::setw(width) << nickName << "|";
		std::cout << std::setw(width) << num << "|\n";
		std::cout << "-------------------------------------------|\n";
	}
	std:: cout << "give me index : \n";
	std::getline(std::cin, index);
	if (check_num(index) == 0)
		std:: cout << "index is not number.\n";
	else
	{
		int idx = atoi(index.c_str());
		if(idx >= 0 && idx <= 7 && getContact(idx).getFirstName().length() != 0)
		{
			std:: cout << "first name --- > " << getContact(idx).getFirstName() << std:: endl;
			std:: cout << "last  name --- > " << getContact(idx).getlastName() << std:: endl;
			std:: cout << "nick  name --- > " << getContact(idx).getNickName() << std:: endl;
			std:: cout << "  number   --- > " << getContact(idx).getNumber() << std:: endl;
		}
		else
			std:: cout << "This index does not exist.\n";
	}
}
