#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip> 
#include <cstring>

class Contact{
    private:
        std:: string first_name;
        std:: string last_name;
        std:: string nickname;
        std:: string number;
    public:
        std:: string getFirstName();
        std:: string getlastName();
        std:: string getNickName();
        std:: string getNumber();
    
        void setFirstName(std:: string str);
        void setLastName(std:: string str);
        void setNickName(std:: string str);
        void setNumber(std:: string str);
};
#endif
