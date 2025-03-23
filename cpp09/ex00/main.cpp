#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>
// case two , february 29 2021

void trim(std::string& str, const std::string tr)
{
    size_t first = str.find_first_not_of(tr);
    size_t last = str.find_last_not_of(tr);
    if (first == std::string::npos || last == std::string::npos)
        return ;
    str = str.substr(first, last - first + 1);
}

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
    if(str[0] == '+' || str[0] == '-')
		str.erase(0, 1);
    if (!str[0])
        throw std::runtime_error("Error: not a number");
    for(int i = 0; str[i]; i++)
    {
        if(!isdigit(str[i]) && str[i] != '.')
            throw std::runtime_error("Error: not a number");
    }
    if(count_char(str, '.') > 1 || str == ".")
		throw std::runtime_error("Error: not a number");
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
    struct tm tm = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
    //sama ta3issa
    return 1;
}


void check_value(std::string str)
{
    if (is_number(str))
	{
		if(atof(str.c_str()) < 0)
			throw std::runtime_error("Error: not a positive number.");
		else if(atof(str.c_str()) > 2147483647)
			throw std::runtime_error("Error: too large a number.");
	}
}
void parce_line(std::string str)
{
    std::map<int, std::string> t;
	if(count_char(str, '|') != 1)
		throw std::runtime_error("Error: bad input => " + str);
	t = split(str, '|');
	if (t.size() != 2)
		throw std::runtime_error("Error: bad input => " + str);
	trim(t[0], " \t");
	trim(t[1], " \t");
	if(!check_key((t[0])))
		throw std::runtime_error("Error: bad input => " + str);
	check_value(t[1]);
}

void search(std::string file_name, std::map<std::string, double> data)
{
    std::string line;
    std::ifstream file(file_name.c_str());
    if(!file.is_open())
        throw std::runtime_error("can't open " + file_name);
    std::map<int, std::string> t;
    std::map<std::string, double>::iterator it;
    std::getline(file, line);
    if(line != "date | value")
        throw std::runtime_error("Error: invalid file format");
    while(std::getline(file, line))
    {
        try
        {
            if (line.empty())
                continue ;
            parce_line(line);
			t = split(line, '|');
			trim(t[0], " \t");
			it = data.upper_bound(t[0]); //awal 3adad akbar 9at3an 
            if (it == data.begin())
                throw std::runtime_error("there is no lower date");
            it--; // kifach katkhdem o trow exp ila mal9ach li sgher mnooo 
			if(it != data.end())
				std::cout << t[0] << " => " << t[1] << " = " << it->second * atof(t[1].c_str()) << std::endl;// * atoi(t[1].c_str())
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int main(int arc, char **arv)
{
    if(arc != 2)
        exit(1);
    try
	{
		std::map<std::string, double> data;
		std::map<std::string, std::string> ff;
		std::ifstream data_file("data.csv");
        if(!data_file.is_open())
            throw std::runtime_error("can't open data.csv");
		std::string line;
		while(std::getline(data_file, line))
		{
			if (line.length() > 11)
                data[line.substr(0, 10)] = atof(line.substr(11).c_str());
		}
		search(arv[1], data);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    
}
