#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip> 
#include <cstring>
#include <cstdlib>
#include <cctype>


class Contact{
    private:
        std:: string first_name;
        std:: string last_name;
        std:: string nickname;
        std:: string number;
        std:: string darkest_secret;
    public:
        std:: string getFirstName();
        std:: string getlastName();
        std:: string getNickName();
        std:: string getNumber();
        std:: string getDarkset_secret();
    
        void setFirstName(std:: string str);
        void setLastName(std:: string str);
        void setNickName(std:: string str);
        void setNumber(std:: string str);
        void setDarkset_secret(std:: string str);
};
#endif
