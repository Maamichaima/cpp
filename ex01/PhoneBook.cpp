#include "PhoneBook.hpp"
#include "Contact.hpp"
Contact& PhoneBook::getContact(int i)// contact
{
	return tab[i];
}

void PhoneBook::Add_New_Contact(int i, std:: string number, std::string first_name, std::string last_name, std::string nickname)
{
	Contact& c = tab[i];

	c.setNumber(number);
	c.setFirstName(first_name);
	c.setLastName(last_name);
	c.setNickName(nickname);
}

void PhoneBook::search()
{
	int i = 0;
	int width = 10;
	std::string index;
	std::string firstName, lastName, nickName;
	
	std::cout << std::setw(width) << "first name" << "|";
	std::cout << std::setw(width) << "last name" << "|";
	std::cout << std::setw(width) << "nick name" << "|";
	std::cout << std::setw(width) << "number" << "\n";
	std::cout << "-------------------------------------------\n";
	for (int i = 0; i <= 7; ++i)
	{
		firstName = getContact(i).getFirstName();
		lastName = getContact(i).getlastName();
		nickName = getContact(i).getNickName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0,9) + ".";
		if (nickName.length() > 10)
			nickName = nickName.substr(0,9) + ".";
		std::cout << std::setw(width) << firstName << "|";
		std::cout << std::setw(width) << lastName << "|";
		std::cout << std::setw(width) << nickName << "|";
		std::cout << std::setw(width) << getContact(i).getNumber() << std::endl;
	}
	std:: cout << "give me index";
	std::getline(std::cin, index);
	int idx = std::stoi(index);
	std:: cout << "name is ";
	std:: cout << getContact(idx).getFirstName();
}
