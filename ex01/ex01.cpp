#include "Contact.hpp"
#include "PhoneBook.hpp"

int main ()
{
    PhoneBook p;
	std::string f_n;
	std::string l_n;
	std::string n_n;
	std::string ligne;
	std::string n;
	std::string index;
	int i = 0;
    
	while(1)
	{
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
			p.Add_New_Contact(i, n, f_n, l_n, n_n);
			i++;
		}
		if(ligne == "SEARCH")
		{
			i = 0;
			const int width = 10;
			for (int i = 0; i < 7; ++i)
			{
				if (p.getContact(i).getFirstName().length() > 10)
				{
					std::cout << "hani\n";
				}
				std::cout << std::setw(width) << p.getContact(i).getFirstName() << "|";
				std::cout << std::setw(width) << p.getContact(i).getlastName() << "|";
				std::cout << std::setw(width) << p.getContact(i).getNickName() << "|";
				std::cout << std::setw(width) << p.getContact(i).getNumber() << std::endl;
			}
			std:: cout << "give me index";
			std::getline(std::cin, index);
			int idx = std::stoi(index);
			std:: cout << "name is ";
			std:: cout << p.getContact(idx).getFirstName();
		}
		if(ligne == "EXIT")
			return 0;
	}
}
