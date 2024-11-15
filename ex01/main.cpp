#include "Contact.hpp"
#include "PhoneBook.hpp"

int main ()
{
    PhoneBook p;
	std::string ligne;
    
	while(1)
	{
		std::cout << "\"ADD\" OR \"SEARCH\" OR \"EXIT\"\n";
		getline(std::cin, ligne);//9lbi 3la had lkhra dyal istream
		// if(std::cin.eof())
		// 	return 1;
		if(ligne == "ADD")
			p.Add_New_Contact();
		else if(ligne == "SEARCH")
			p.search();
		else if(ligne == "EXIT")
			return 0;
	}
}
