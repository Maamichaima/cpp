#include <iostream>
#include <string>


class Contact{
    private:
        std:: string first_name;
        std:: string last_name;
        std:: string nickname;
        std:: string number;
    public:
        std:: string getFirstName()
        {
            return first_name;
        }
        std:: string getlastName()
        {
            return last_name;
        }
        std:: string getNickName()
        {
            return nickname;
        }
        std:: string getNumber()
        {
            return number;
        }
    
        void setFirstName(std:: string str)
        {
            first_name = str;
        }
        void setLastName(std:: string str)
        {
            last_name = str;
        }
        void setNickName(std:: string str)
        {
            nickname = str;
        }
        void setNumber(std:: string str)
        {
            number = str;
        }
};

class PhoneBook{
    private:
        Contact tab[8];
    public:
        Contact& getContact(int i)// contact
        {
            return tab[i];
        }

        void Add_New_Contact(int i, std:: string number, std::string first_name, std::string last_name, std::string nickname)
        {
            Contact& c = tab[i];

            c.setNumber(number);
            c.setFirstName(first_name);
            c.setLastName(last_name);
            c.setNickName(nickname);
        }
};
