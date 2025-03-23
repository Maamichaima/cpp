#include "BitcoinExchange.hpp"

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
