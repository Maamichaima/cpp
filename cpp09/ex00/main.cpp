#include <iostream>
#include <map>
#include <fstream>

int main(int arc, char **arv)
{
    // if(arc != 2)
    //     exit(1);
    
    std::map<std::string, std::string> data;
    std::ifstream file("data.csv");//check if is open
    std::string line;
    std::string key;
    std::string value;
    while(std::getline(file, line))
    {
        // map[]
        // std::cout << data[line.substr(0, 9)] << "\n";
        data[line.substr(0, 9)] = line.substr(11);
    }
}