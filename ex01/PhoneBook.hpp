#ifndef PHONEBOOKE_HPP
# define PHONEBOOKE_HPP
#include "Contact.hpp"

class PhoneBook{
    private:
        Contact tab[8];
    public:
        Contact& getContact(int i);
        void Add_New_Contact(int i, std:: string number, std::string first_name, std::string last_name, std::string nickname);
		void search();
};
#endif
