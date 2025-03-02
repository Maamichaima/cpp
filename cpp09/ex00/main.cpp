#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
// void searsh_map()

std::map<int, std::string> split(const std::string& str, char delimiter){
    std::map<int, std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (getline(ss, item, delimiter))
    {
        if(item.length() == 0)
            continue;
        result[result.size()] = item;
    }

    return result;
}

int affiche(std::string x)
{
    std::string key, value;
    int i = 0;
    while(x[i] && x[i] != '|')
    {
        std::cout << x[i];
        key[i] = x[i];
        i++;
    }
    std::cout << key << "\n";
    std::size_t pos = x.find('|');
    pos ++;
    if (pos != std::string::npos) 
    {
        value =  x.substr(pos);//strtream
    }
    else
        value = "";
    std::cout << key << "\n";
    std::cout << value << "\n";
    return 0;
}

int count_char(std::string str, char c)
{
    int i = 0;
    int count = 0;

    for(i = 0; str[i]; i++)
    {
        if(str[i] == c)
            count ++;
    }
    return count;
}

int is_number(std::string str)
{
    int i = 0;
    if(str[0] == '+' || str[0] == '-')// checck overflow
        i++;
    for(i = 0; str[i]; i++)
    {
        if(!isalnum(str[i]) && str[i] != '.')
            return 0;
    }
    if(count_char(str, '.') > 1)
        return 0;
    return 1;
}

int is_int(std::string str)
{
    int i;
    for(i = 0; str[i]; i++)
    {
        if(!isalnum(str[i]))
            return 0;
    }
    return 1;
}

int check_key(std::string str)
{
    std::string word;
    std::map<int, std::string> date;
    long int m, j, y;
    int count = 0;
    struct tm tm = {0};
    // 2003
    if(strptime(str.c_str(), "%Y-%m-%d", &tm))
    {
        y = tm.tm_year + 1900;
        m = tm.tm_mon + 1;
        j = tm.tm_mday;
    }
    else
        return 0;
    if(y <= 0 || m  <= 0 || m > 12 || j <= 0 || j > 31)
        return 0;
    if((m == 2 && j > 29) || (m == 4 && j > 30) || (m == 6 && j > 30) || (m == 9 && j > 30) || (m == 11 && j > 30))
        return 0;
    return 1;
}


int check_value(std::string str)
{
    if (!is_number(str))
        return 0;
    return 1;
}
int parce_line(std::string str)
{
    // std::string line;
    std::map<int, std::string> t;
    // std::ifstream file(str);
    // std::map<std::string, std::string> ff;
    // std::getline(file, line);
    // if(line != "date | value")
    // {
    //     //yhrow exeption 
    //     return 0;
    // }
    // while(std::getline(file, line))
    // {
        if(count_char(str, '|') != 1)
            return 0;
        t = split(str, ' ');// b |
        if(!check_key((t[0])))
            return 0;
        if(!check_value(t[1]))
            return 0;
    //     break;
    // }
    return 1;
}

void search(std::string file_name, std::map<std::string, std::string> data)
{
    std::string line;
    std::ifstream file(file_name);
    std::map<int, std::string> t;
    // check lbdya
    std::getline(file, line);
    if(line != "date | value")
    {
        //yhrow exeption 
        // return 0;
    }
    while(std::getline(file, line))
    {
        try
        {
            if(parce_line(line))
            {
            std::cout <<" hhh";
            }
            else
            {
                t = split(line, ' ');
                // printi msg
                std::cout << data[t[0]] << "\n";
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int main(int arc, char **arv)
{
    // if(arc != 2)
    //     exit(1);
    
    std::map<std::string, std::string> data;
    std::map<std::string, std::string> ff;
    std::ifstream data_file("data.csv");//check if is open

    std::string line;
    std::string key;
    std::string value;

    while(std::getline(data_file, line))
    {
        // std::cout << data[line.substr(0, 9)] << line.substr(0, 9) << "\n";
        data[line.substr(0, 10)] = line.substr(11);
    }
    search(arv[1], data);
    // std::map<std::string, std::string>::iterator it = data.find("2011-03-08");
    // std::cout << "Key: " << it->first
    //      << ", Value: " << it->second << std::endl;
    // std::cout << parce_file(arv[1]);
    // std::map<std::string, std::string>::iterator it = data.begin();

    // // Iterate through the map and print the elements
    // while (it != data.end()) {
    //     std::cout << "Key: " << it->first
    //          << ", Value: " << it->second << std::endl;
    //     ++it;
    // }
}