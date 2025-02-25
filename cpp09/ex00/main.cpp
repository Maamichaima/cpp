#include <iostream>
#include <map>
#include <fstream>

// void searsh_map()

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

int parce_file(std::string str)
{
    std::string line;
    std::ifstream file(str);
    std::map<std::string, std::string> ff;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        // std::cout << line << "\n";
        if()
        ff[line.substr(0, 9)] = line.substr(13);
        // affiche(line);
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

    std::map<std::string, std::string>::iterator it = data.find("2011-03-08");
    std::cout << "Key: " << it->first
         << ", Value: " << it->second << std::endl;

    // std::map<std::string, std::string>::iterator it = data.begin();

    // // Iterate through the map and print the elements
    // while (it != data.end()) {
    //     std::cout << "Key: " << it->first
    //          << ", Value: " << it->second << std::endl;
    //     ++it;
    // }
}