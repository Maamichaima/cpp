#ifndef PHONEBOOKE_HPP
# define PHONEBOOKE_HPP
#include "Contact.hpp"

class PhoneBook{
    private:
        Contact tab[8];
		int index;
		std:: string m_error[4];
		std:: string att[4];
    public:
        Contact& getContact(int i);
        void Add_New_Contact();
		void search();
		// bool check_num(const std::string& str);
		PhoneBook();
};
#endif
