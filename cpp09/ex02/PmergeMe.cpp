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
	std::cout << "\n";
}

void print_int_d(std::deque<int> x)
{
	std::cout << std::endl;
	for (std::deque<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << "[" << *it << "] ";
    }
}

int is_dalid(std::string c)
{
	int i = 0;

	if(c[i] == '+' || c[i] =='-')
		i++;
	if(!c[i])
		return 0;
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

std::deque<int> string_to_int_d(std::deque<std::string> str)
{
	std::deque<int> num;
	double n;
	int i = 0;

	while(i < str.size())
	{
		if(!is_dalid(str[i]))
			throw std::runtime_error("pas un num");
		n = atof(str[i].c_str());
		if(n < 0 )
			throw std::runtime_error("negative");
		num.push_back(n);
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

std::deque<std::pair<int, int> > get_part_d(std::deque<std::pair<int, int> > x, int start, int size)
{
	std::deque<std::pair<int, int> > sub;
	
	for(int i = start; i < x.size(); i++)
	{
		sub.push_back(x[i]);
		if (sub.size() == size)
			break ;
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
    while (i < left.size())
	{
		x[k++] = left[i++];
	}
	while (j < right.size())
	{
		x[k++] = right[j++];
	}
}

void insertionSort(std::deque<std::pair<int, int> > & arr, int n)
{
	for (int i = 1; i < n; ++i) {
		std::pair<int, int> key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j].first > key.first) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void merg_sort_d(std::deque<std::pair<int, int> > &x)
{
	if(x.size() <= 3)
	{
		insertionSort(x, x.size());
		return ;
	}
	std::deque<std::pair<int, int> > left, right;
	left = get_part_d(x, 0, 3);
	insertionSort(left, 3);
	right = get_part_d(x, left.size(), x.size() - left.size());
	merg_sort_d(right);
	// std::cout << "----left-----\n";
	// print_d(left);
	// std::cout << "----right-----\n";
	// print_d(right);
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
		start = sq[i_sq];
		while(start > end)
		{
			if(start <= lowset.size())
			{
				index = getIndex_d(largest, lowset[start - 1]);
				largest.insert(largest.begin() + index, lowset[start - 1]);
			}
			start--;
		}
		end = sq[i_sq];
		i_sq++;
	}
}

std::deque<int> sort_d(std::deque<std::pair<int, int> > x)
{
	merg_sort_d(x);

	std::deque<int> largest = make_sequence_d(x, "largest");
	std::deque<int> lowest = make_sequence_d(x, "lowest");

	std::deque<int> sq = get_JacobsthalSequence_d(largest.size() - 1);
	// print_int_d(sq);
	search_stock_d(largest, lowest, sq);
	return largest;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}