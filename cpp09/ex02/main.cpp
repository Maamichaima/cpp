#include "PmergeMe.hpp"
#include <set>
#include <sstream>
#include <iostream>
#include <utility>

std::vector<std::string> split(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (getline(ss, item, delimiter))
    {
        if(item.length() == 0)
            continue;
		result.push_back(item);
    }
    return result;
}

std::vector<int> string_to_int(std::vector<std::string> str)
{
	std::vector<int> num;
	int i = 0;

	while(i < str.size())
	{
		// std::cout << num[i] << "\n";
		num.push_back(atoi(str[i].c_str()));
		i++;
	}
	return num;
}

std::set<std::pair<int, int> > makePairs(std::string arg)
{
	std::vector<int> numbers;
    std::set<std::pair<int, int> > x;

	numbers = string_to_int(split(arg, ' '));
	for(int i = 0; i < numbers.size(); i += 2)
	{
		if(i + 1 >= numbers.size())
			numbers[i + 1] = -1;
		//swap
		x.insert(std::make_pair(numbers[i], numbers[i + 1]));
	}
	return x;
}

// std::set<std::pair<int, int> > sortPairs(std::set<std::pair<int, int> > x)
// {

// }

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "entrer <numbers>" << std::endl;
        return 1;
    }

    std::set<std::pair<int, int> > x = makePairs(av[1]);

	int i = 0;
	for (std::set<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }

    return 0;
}