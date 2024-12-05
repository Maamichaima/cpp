#include <fstream>
#include <iostream>

int main(int c, char **v)
{
    if(c != 4)
    {
        std::cout << "<infile> <s1> <s2> \n" ;
        return (1);
    }

    std::string ligne;
    std::string v1 = v[1];
    std::string v2 = v[2];
    std::string v3 = v[3];
    std::string name = v1 + ".replace";
    size_t pos;

    std::ifstream infile(v[1]);
    if (!infile.is_open())
    {
        std::cout << "Error: Could not open file.\n";
        return (1);
    }
    std::ofstream outfile(name.c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error: Could not open file.\n";
        return (1);
    }

    while(std::getline(infile, ligne))
    {
        pos = 0;
        pos = ligne.find(v2, pos);
        while(pos != size_t(-1) && !v2.empty())
        {
            ligne.erase(pos, v2.length());
            ligne.insert(pos, v3);
            pos = ligne.find(v2, pos + 1);
        }
        outfile << ligne;
        if (!infile.eof())
            outfile << std::endl;
    }

    infile.close();
    outfile.close();
}

