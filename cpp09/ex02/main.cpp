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
void print(std::vector<std::pair<int, int > > x)
{
	for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
}

void print_int(std::vector<int> x)
{
	std::cout << std::endl;
	for (std::vector<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << *it << "] ";
    }
}
std::vector<int> string_to_int(std::vector<std::string> str)
{
	std::vector<int> num;
	int i = 0;

	while(i < str.size())
	{
		num.push_back(atoi(str[i].c_str()));
		i++;
	}
	return num;
}

std::vector<std::pair<int, int> > makePairs(std::string arg)
{
	std::vector<int> numbers;
    std::vector<std::pair<int, int> > x;

	numbers = string_to_int(split(arg, ' '));
	for(int i = 0; i < numbers.size(); i += 2)
	{
		if(i + 1 >= numbers.size())
			numbers[i + 1] = -1;
		if(numbers[i] > numbers[i + 1])
			x.push_back(std::make_pair(numbers[i], numbers[i + 1]));
		else
			x.push_back(std::make_pair(numbers[i + 1], numbers[i]));
	}
	return x;
}

std::vector<int> make_sequence(std::vector<std::pair<int, int> > x, std::string str)
{
	std::vector<int> largest, lowest;

	for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
		largest.push_back(it->first);
		lowest.push_back(it->second);
		// std::cout << it->first << "  " << it->second;
	}
	if(str == "lowest")
		return lowest;
	else
		return largest;
}
std::vector<std::pair<int, int> > get_part(std::vector<std::pair<int, int> > x, int start, int end)
{
	std::vector<std::pair<int, int> > sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

std::vector<int> get_sub(std::vector<int> x, int start, int end)
{
	std::vector<int> sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

void check_edit(std::vector<std::pair<int, int> > &x, std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < left.size() && j < right.size())
	{
		if(left[i].first < right[j].first)
		{
			x[k] = left[i];
			i++;
		}
		else
		{
			x[k] = right[j];
			j++;
		}
		k++;
	}
    while (i < left.size()) {
        x[k++] = left[i++];
    }// machi daroriii
    while (j < right.size()) {
        x[k++] = right[j++];
    }
}

void merg_sort(std::vector<std::pair<int, int> > &x, int i_start, int i_end)
{
	int mid = i_start + (i_end - i_start) / 2;
	if(i_start >= i_end)
	{
		return ;
	}
	std::vector<std::pair<int, int> > left, right;
	left = get_part(x, i_start, mid);
	right = get_part(x, mid + 1, i_end);
	// std::cout << "\n----------9beel-----------\n";
	// print(x);
	// std::cout << "\n---------------------\n";
	merg_sort(left, 0, left.size() -1);
	merg_sort(right, 0, right.size() - 1);
	// std::cout << "\n----------soort-----------\n";
	check_edit(x, left, right);
	// print(x);
	// std::cout << "left --> " ;
	// print(left);
	// std::cout << "right --> " ;
	// print(right);
}

void add_index(std::vector<int> &sq)
{
	int i = 0;
	
	for(i = 0; i < sq.size(); i++)
	{
		if(sq[i + 1] - sq[i] > 1)
		{
			sq.insert(sq.begin() + i + 1, sq[i] + 1);
			i--;
		}
	}
}

std::vector<int> get_JacobsthalSequence(int max)
{
	int j = 2;
	std::vector<int> sq;
	int nb = 0;
	
	sq.push_back(0);
	sq.push_back(1);
	
	while(nb < max)
	{
		nb = sq[j - 1] + 2 * sq[j - 2];
		sq.push_back(nb);
		j++;
	}
	add_index(sq);
	// std::cout << std::endl;
	return sq;
}

int getIndex(std::vector<int> largest, int x)
{
	int mid;
	print_int(largest);
	if(largest.size() < 3)
	{
		// hbees
		int index = 0;
		// print_int(largest);
		if(largest.size() == 1)
		{
			if(x > largest[0])
				index = 1;
			else
				index = 0;
			return index;
		}
		else
		{
			if(x > largest[1] && x > largest[0])
				index = 2;
			else if(x > largest[0] && x < largest[1])
				index = 1;
			else if(x < largest[0])
				index = 0;
		}
		return index ;
	}
	mid = largest.size() / 2;
	if(largest[mid] < x)
	{
		return (mid + getIndex(get_sub(largest, mid, largest.size() - 1), x));
	}
	else
	{
		return (getIndex(get_sub(largest, 0, mid - 1), x));
	}
	// return 0;
}

void search_stock(std::vector<int> &largest, std::vector<int> lowset, std::vector<int> sq)
{
	int i = 0;
	int index;

	//push lwel
	largest.insert(largest.begin(), lowset[0]);
	// lowset.pop_back();
	// print_int(largest);
	// print_int(lowset);
	for(i = 2; i < sq.size(); i++)
	{
		// print(sq[i]);
		index = getIndex(largest, lowset[sq[i]]);
		// if(index != 0)
		// 	index--;
		largest.insert(largest.begin() + index, lowset[sq[i]]);
		std::cout << "\n" << "" << lowset[sq[i]] << " index --> " << index << "\n";
		print_int(largest);
	}
}


int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "entrer <numbers>" << std::endl;
        return 1;
    }
	
    std::vector<std::pair<int, int> > x = makePairs(av[1]);

	merg_sort(x, 0, x.size() - 1);
	std::cout << "\n-----------------------------------\n";
	print(x);
	std::cout << "\n-----------------------------------\n";
	std::vector<int> largest = make_sequence(x, "largest");
	std::vector<int> lowest = make_sequence(x, "lowest");
	for(int i = 0; i < largest.size(); i++)
	{
		std::cout << largest[i] << "    "; 
	}
	std::cout << "\n";
	for(int i = 0; i < lowest.size(); i++)
	{
		std::cout << lowest[i] << "    ";
	}
	std::vector<int> sq = get_JacobsthalSequence(11);
	// Binary search
	search_stock(largest, lowest, sq);
	// std::cout << x.size();
	// print(x);
	// std::cout << "\n";
	// make_sequence(x);
	
	// int i = 0;
	// for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	// {
    //     std::cout << "[" << it->first << ", " << it->second << "] ";
    // }

    return 0;
}