#ifndef PHONEBOOKE_HPP
# define PHONEBOOKE_HPP
#include "Contact.hpp"

class PhoneBook{
    private:
        Contact tab[8];
		int index;
		std:: string m_error[5];
    public:
        Contact getContact(int i);//bedli hadi bdik l3adiya 
        void Add_New_Contact();
		void search();
		void showContact(int index);
		// bool check_num(const std::string& str);
		PhoneBook();
};
#endif
 