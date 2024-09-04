#include "Contact.hpp"

int main ()
{
    PhoneBook p;
	std::string f_n;
	std::string l_n;
	std::string n_n;
	std::string ligne;
	std::string n;
    
	std::getline(std::cin, ligne);
	if(ligne == "ADD")
	{
		std::cout << "give me first name :";
		std::getline(std::cin, f_n);
		std::cout << "give me last name :";
		std::getline(std::cin, l_n);
		std::cout << "give me nickname :";
		std::getline(std::cin, n_n);
		std::cout << "give me number :";
		std::getline(std::cin, n);
		p.Add_New_Contact(0, n, f_n, l_n, "hh");
		std:: cout << p.getContact(0).getFirstName() << std:: endl;
		std:: cout << p.getContact(0).getlastName() << std:: endl;
		std:: cout << p.getContact(0).getlastName() << std:: endl;
		std:: cout << p.getContact(0).getNumber() << std:: endl;
	}

}