#include "PmergeMe.hpp"
#include <set>
#include <sstream>
#include <iostream>
#include <utility>

std::vector<std::string> split_v(const std::string& str, char delimiter){
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
void print_v(std::vector<std::pair<int, int > > x)
{
	for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
}

void print_int_v(std::vector<int> x)
{
	std::cout << std::endl;
	for (std::vector<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << *it << "] ";
    }
}

int is_valid(std::string c)
{
	int i = 0;

	if(c[i] == '+' || c[i] =='-')
		i++;
	while(c[i])
	{
		if(!isdigit(c[i]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

std::vector<int> string_to_int_v(std::vector<std::string> str)
{
	std::vector<int> num;
	double n;
	int i = 0;

	while(i < str.size())
	{
		//check and trow exepltion
		if(!is_valid(str[i]))
			throw std::runtime_error("pas un num");
		n = atof(str[i].c_str());
		if(n < 0 )//|| n > 21)
			throw std::runtime_error("negative");
		num.push_back(n);
		i++;
	}
	return num;
}
// done
std::vector<std::pair<int, int> > makePairs_v(std::vector<int> numbers)
{
    std::vector<std::pair<int, int> > x;

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

std::vector<int> make_sequence_v(std::vector<std::pair<int, int> > x, std::string str)
{
	std::vector<int> largest, lowest;

	for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
		largest.push_back(it->first);
		lowest.push_back(it->second);
	}
	if(str == "lowest")
		return lowest;
	else
		return largest;
}

std::vector<std::pair<int, int> > get_part_v(std::vector<std::pair<int, int> > x, int start, int end)
{
	std::vector<std::pair<int, int> > sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

std::vector<int> get_sub_v(std::vector<int> x, int start, int end)
{
	std::vector<int> sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

void check_edit_v(std::vector<std::pair<int, int> > &x, std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right)
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

void merg_sort_v(std::vector<std::pair<int, int> > &x, int i_start, int i_end)
{
	int mid = i_start + (i_end - i_start) / 2;
	if(i_start >= i_end)
		return ;
	std::vector<std::pair<int, int> > left, right;
	left = get_part_v(x, i_start, mid);
	right = get_part_v(x, mid + 1, i_end);
	merg_sort_v(left, 0, left.size() -1);
	merg_sort_v(right, 0, right.size() - 1);
	check_edit_v(x, left, right);
}

std::vector<int> get_JacobsthalSequence_v(int max)
{
	int j = 2;
	int found = 0;
	std::vector<int> sq;
	int nb = 0;
	
	sq.push_back(0);
	sq.push_back(1);
	while(found == 0)
	{
		nb = sq[j - 1] + 2 * sq[j - 2];
		if(nb > max)
			found = 1;
		sq.push_back(nb);
		j++;
	}
	return sq;
}

int getIndex_v(std::vector<int> largest, int x)
{
	int mid;
	// print_int_v(largest);
	if(largest.size() < 3)
	{
		int index = 0;
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
			if(x > largest[1] && x >= largest[0])
				index = 2;
			else if(x >= largest[0] && x <= largest[1])
				index = 1;
			else if(x <= largest[0])
				index = 0;
		}
		// std::cout <<index << "\n";
		return index ;
	}
	mid = largest.size() / 2;
	if(largest[mid] < x)
		return (mid + getIndex_v(get_sub_v(largest, mid, largest.size() - 1), x));
	else
		return (getIndex_v(get_sub_v(largest, 0, mid - 1), x));
}


void search_stock_v(std::vector<int> &largest, std::vector<int> lowset, std::vector<int> sq)
{
	int i = 0;
	int index;

	int i_sq = 0;
	int start, end;
	end = 0;
	while(i_sq <= sq.size())
	{
		// std::cout << "i_sq -- > " << i_sq << "\n";
		start = sq[i_sq];
		while(start > end)
		{
			if(start <= lowset.size())
			{
				// std::cout << "\n" << "" << lowset[start - 1] << " index --> " << start - 1 << "\n";
				index = getIndex_v(largest, lowset[start - 1]);
				largest.insert(largest.begin() + index, lowset[start - 1]);
				// print_int_v(largest);
			}
			start--;
		}
		end = sq[i_sq];
		i_sq++;
	}
}

std::vector<int> sort_v(std::vector<std::pair<int, int> > x)
{
	merg_sort_v(x, 0, x.size() - 1);
	exit (0);
	// std::cout << "\n-----------------pairs sort------------------\n";
	// print_v(x);
	// std::cout << "\n---------------------------------------------\n";
	std::vector<int> largest = make_sequence_v(x, "largest");
	std::vector<int> lowest = make_sequence_v(x, "lowest");
	// std::cout << "\n-----------------------largset-----------------------\n";
	// print_int_v(largest);
	// std::cout << "\n-----------------------lowest-----------------------\n";
	// print_int_v(lowest);
	// std::cout << "\n----------------------------------------------\n";
	std::vector<int> sq = get_JacobsthalSequence_v(largest.size() - 1);
	// print_int_v(sq);
	// Binary search
	search_stock_v(largest, lowest, sq);
	return largest;
}

PmergeMe::PmergeMe(std::string arg)
{
	std::vector<int> vc;
	std::deque<int> dq;

	vc = string_to_int_v(split_v(arg, ' '));
	dq = string_to_int_d(split_d(arg, ' '));
	this->dq = dq;
	this->vc = vc;
}

void PmergeMe::sort(std::vector<int> vc)
{
	std::vector<std::pair<int, int> > pairs;

	pairs = makePairs_v(vc);

	this->vc = sort_v(pairs);
}

void PmergeMe::sort(std::deque<int> dq)
{
	std::deque<std::pair<int, int> > pairs;

	pairs = makePairs_d(dq);

	this->dq = sort_d(pairs);
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "entrer <numbers>" << std::endl;
        return 1;
    }
	try
	{
		PmergeMe nb(av[1]);
		std::cout <<"-----------vector-------------\n";
		nb.sort(nb.vc);
		print_int_v(nb.vc);
		std::cout <<"\n-----------deque-------------\n";
		nb.sort(nb.dq);
		print_int_d(nb.dq);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

    return 0;
}