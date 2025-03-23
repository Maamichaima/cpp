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

std::deque<int> string_to_int_d(std::deque<std::string> str)
{
	std::deque<int> num;
	double n;
	size_t i = 0;

	while(i < str.size())
	{
		if(!is_valid(str[i]))
			throw std::runtime_error("not a integer");
		n = atof(str[i].c_str());
		if(n < 0 || n > std::numeric_limits<int>::max())
			throw std::runtime_error("not a positive integer");
		num.push_back(n);
		i++;
	}
	return num;
}

std::deque<std::pair<int, int> > makePairs_d(std::deque<int> numbers)
{
    std::deque<std::pair<int, int> > x;

	for(size_t i = 0; i < numbers.size(); i += 2)
	{
		if(i + 1 >= numbers.size())
			numbers.push_back(-1);
		if(numbers[i] > numbers[i + 1])
			x.push_back(std::make_pair(numbers[i], numbers[i + 1]));
		else
			x.push_back(std::make_pair(numbers[i + 1], numbers[i]));
	}
	return x;
}

std::deque<int> make_sequence_d(std::deque<std::pair<int, int> > x, std::string str)
{
	std::deque<int> temp;

	for (std::deque<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
		if(str == "lowest")
			temp.push_back(it->second);
		else
			temp.push_back(it->first);
	}
	return temp;
}

std::deque<std::pair<int, int> > get_part_d(std::deque<std::pair<int, int> > x, int start, size_t size)
{
	std::deque<std::pair<int, int> > sub;
	
	for(size_t i = start; i < x.size(); i++)
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
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
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

void insertionSort(std::deque<std::pair<int, int> > & arr)
{
	for (size_t i = 1; i < arr.size(); ++i) {
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
		insertionSort(x);
		return ;
	}
	std::deque<std::pair<int, int> > left, right;
	left = get_part_d(x, 0, 3);
	insertionSort(left);
	right = get_part_d(x, left.size(), x.size() - left.size());
	merg_sort_d(right);
	check_edit_d(x, left, right);
}

std::deque<int> get_JacobsthalSequence_d(int max)
{
	int j = 2;
	std::deque<int> sq;
	int nb = 0;
	
	sq.push_back(0);
	sq.push_back(1);
	while(true)
	{
		nb = sq[j - 1] + 2 * sq[j - 2];
		sq.push_back(nb);
		if(nb > max)
			break;
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
	int index;

	size_t i_sq = 0;
	size_t start, end;
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
	search_stock_d(largest, lowest, sq);
	if(!largest.empty() && largest[0] == -1)
		largest.pop_front();
	return largest;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if(this != &other)
	{
		this->d_str = other.d_str;
		this->v_str = other.v_str;
		this->dq = other.dq;
		this->vc = other.vc;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}