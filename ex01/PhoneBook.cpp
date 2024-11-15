#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact PhoneBook::getContact(int i)
{
	return tab[i];
}

void PhoneBook::Add_New_Contact()
{
	std::string f_n;
	std::string l_n;
	std::string n_n;
	std::string n;
	std:: string att[5];

	for(int i = 0; i < 5; i++)
	{
		std::cout << "give me "<< m_error[i] << " : ";
		getline(std::cin, att[i]);
		if(att[i].length() == 0)
		{
			std::cout << m_error[i] <<" is not valide \n";
			return;
		}
	}
	if(index == 8)
		index = 0;
	tab[index].setFirstName(att[0]);
	tab[index].setLastName(att[1]);
	tab[index].setNickName(att[2]);
	tab[index].setNumber(att[3]);
	tab[index].setDarkset_secre(att[4]);
	index++;
}

PhoneBook::PhoneBook()
{
	index = 0;
	m_error[0] = "first name";
	m_error[1] = "last name";
	m_error[2] = "nick name";
	m_error[3] = "number";
	m_error[4] = "darkest secre";
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

void PhoneBook:: showContact(int idx)
{
	if(idx >= 0 && idx <= 7 && getContact(idx).getFirstName().length() != 0)
	{
		std:: cout << "first name --- > " << getContact(idx).getFirstName() << std:: endl;
		std:: cout << "last  name --- > " << getContact(idx).getlastName() << std:: endl;
		std:: cout << "nick  name --- > " << getContact(idx).getNickName() << std:: endl;
		std:: cout << "number     --- > " << getContact(idx).getNumber() << std:: endl;
	}
	else
		std:: cout << "This index does not exist.\n";
}

void PhoneBook::search()
{
	int width = 10;
	std::string index;
	std:: string att[4];
	
	std::cout << std::setw(width) << "index" << "|";
	std::cout << std::setw(width) << "first name" << "|";
	std::cout << std::setw(width) << "last name" << "|";
	std::cout << std::setw(width) << "nick name" << "|";
	std::cout << std::setw(width) << "number" << "|\n";
	std::cout << "------------------------------------------------------|\n";
	for (int i = 0; i <= 7; ++i)
	{
		att[0] = getContact(i).getFirstName();
		att[1] = getContact(i).getlastName();
		att[2] = getContact(i).getNickName();
		att[3] = getContact(i).getNumber();
		std::cout << std::setw(width) << i << "|";
		for(int j = 0; j < 4; j++)
		{
			if (att[j].length() > 10)
				att[j] = att[j].substr(0, 9) + ".";
			std::cout << std::setw(width) << att[j] << "|";
		}
		std::cout << "\n------------------------------------------------------|\n";
	}
	std:: cout << "give me index : \n";
	getline(std::cin, index);
	if (check_num(index) == 0)
		std:: cout << "index is not a number.\n";
	else
	{
		int idx = atoi(index.c_str());
		showContact(idx);
	}
}
