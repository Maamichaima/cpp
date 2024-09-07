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
		std::cout << "\"ADD\" OR \"SEARCH\" OR \"EXIT\"\n";
		std::getline(std::cin, ligne);
		if(ligne == "ADD")
		{
			std::cout << "give me first name :";
			std::getline(std::cin, f_n);
			std::cout << "give me last name :";
			std::getline(std::cin, l_n);
			std::cout << "give me nickname :";
			std::getline(std::cin, n_n);
			std::cout << "give me number :";//check number 
			std::getline(std::cin, n);
			p.Add_New_Contact(i, n, f_n, l_n, n_n);
			i++;
		}
		if(ligne == "SEARCH")
			p.search();
		if(ligne == "EXIT")
			return 0;
	}
}
