#include "PmergeMe.hpp"
#include <set>
#include <sstream>
#include <iostream>
#include <utility>

std::deque<std::string> split_d(const std::string& str, char delimiter){
    std::deque<std::string> result;
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
void print_d(std::deque<std::pair<int, int > > x)
{
	for (std::deque<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
}

void print_int_d(std::deque<int> x)
{
	std::cout << std::endl;
	for (std::deque<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << *it << "] ";
    }
}

std::deque<int> string_to_int_d(std::deque<std::string> str)
{
	std::deque<int> num;
	int i = 0;

	while(i < str.size())
	{
		//check and trow exepltion
		num.push_back(atoi(str[i].c_str()));
		i++;
	}
	return num;
}
// done
std::deque<std::pair<int, int> > makePairs_d(std::deque<int> numbers)
{
    std::deque<std::pair<int, int> > x;

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

std::deque<int> make_sequence_d(std::deque<std::pair<int, int> > x, std::string str)
{
	std::deque<int> largest, lowest;

	for (std::deque<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
		largest.push_back(it->first);
		lowest.push_back(it->second);
	}
	if(str == "lowest")
		return lowest;
	else
		return largest;
}

std::deque<std::pair<int, int> > get_part_d(std::deque<std::pair<int, int> > x, int start, int end)
{
	std::deque<std::pair<int, int> > sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

std::deque<int> get_sub_d(std::deque<int> x, int start, int end)
{
	std::deque<int> sub;
	
	for(int i = start; i <= end; i++)
	{
		sub.push_back(x[i]);
	}
	return sub;
}

void check_edit_d(std::deque<std::pair<int, int> > &x, std::deque<std::pair<int, int> > &left, std::deque<std::pair<int, int> > &right)
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

void merg_sort_d(std::deque<std::pair<int, int> > &x, int i_start, int i_end)
{
	int mid = i_start + (i_end - i_start) / 2;
	if(i_start >= i_end)
		return ;
	std::deque<std::pair<int, int> > left, right;
	left = get_part_d(x, i_start, mid);
	right = get_part_d(x, mid + 1, i_end);
	merg_sort_d(left, 0, left.size() -1);
	merg_sort_d(right, 0, right.size() - 1);
	check_edit_d(x, left, right);
}

std::deque<int> get_JacobsthalSequence_d(int max)
{
	int j = 2;
	int found = 0;
	std::deque<int> sq;
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

int getIndex_d(std::deque<int> largest, int x)
{
	int mid;
	// print_int_d(largest);
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
		return (mid + getIndex_d(get_sub_d(largest, mid, largest.size() - 1), x));
	else
		return (getIndex_d(get_sub_d(largest, 0, mid - 1), x));
}


void search_stock_d(std::deque<int> &largest, std::deque<int> lowset, std::deque<int> sq)
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
				index = getIndex_d(largest, lowset[start - 1]);
				largest.insert(largest.begin() + index, lowset[start - 1]);
				// print_int_d(largest);
			}
			start--;
		}
		end = sq[i_sq];
		i_sq++;
	}
}

std::deque<int> sort_d(std::deque<std::pair<int, int> > x)
{
	merg_sort_d(x, 0, x.size() - 1);
	// std::cout << "\n-----------------pairs sort------------------\n";
	// print_d(x);
	// std::cout << "\n---------------------------------------------\n";
	std::deque<int> largest = make_sequence_d(x, "largest");
	std::deque<int> lowest = make_sequence_d(x, "lowest");
	// std::cout << "\n-----------------------largset-----------------------\n";
	// print_int_d(largest);
	// std::cout << "\n-----------------------lowest-----------------------\n";
	// print_int_d(lowest);
	// std::cout << "\n----------------------------------------------\n";
	std::deque<int> sq = get_JacobsthalSequence_d(largest.size() - 1);
	// print_int_d(sq);
	// Binary search
	search_stock_d(largest, lowest, sq);
	return largest;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}