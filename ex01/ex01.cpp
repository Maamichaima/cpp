#include "Contact.hpp"
#include "PhoneBook.hpp"

int main ()
{
    PhoneBook p;
	std::string ligne;
    
	while(1)
	{
		std::cout << "\"ADD\" OR \"SEARCH\" OR \"EXIT\"\n";
		std::getline(std::cin, ligne);
		// if(std::cin.eof())
		// 	return 1;
		if(ligne == "ADD")
			p.Add_New_Contact();
		if(ligne == "SEARCH")
			p.search();
		if(ligne == "EXIT")
			return 0;
	}
}
