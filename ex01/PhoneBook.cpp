#include "PhoneBook.hpp"
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