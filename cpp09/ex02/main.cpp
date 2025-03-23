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
	std::cout << "\n";
}

void print_int_v(std::vector<int> x)
{
	for (std::vector<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

void print_str_v(std::vector<std::string> x)
{
	for (std::vector<std::string>::iterator it = x.begin(); it != x.end(); ++it)
	{
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

int is_valid(std::string c)
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

std::vector<int> string_to_int_v(std::vector<std::string> str)
{
	std::vector<int> num;
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

std::vector<std::pair<int, int> > makePairs_v(std::vector<int> numbers)
{
    std::vector<std::pair<int, int> > x;

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

std::vector<int> make_sequence_v(std::vector<std::pair<int, int> > x, std::string str)
{
	std::vector<int> temp;

	for (std::vector<std::pair<int, int> >::iterator it = x.begin(); it != x.end(); ++it)
	{
		if(str == "lowest")
			temp.push_back(it->second);
		else
			temp.push_back(it->first);
	}
	return temp;
}

std::vector<std::pair<int, int> > get_part_v(std::vector<std::pair<int, int> > x, int start, size_t size)
{
	std::vector<std::pair<int, int> > sub;
	
	for(size_t i = start; i < x.size(); i++)
	{
		sub.push_back(x[i]);
		if (sub.size() == size)
			break ;
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

void insertionSort(std::vector<std::pair<int, int> > & arr)
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

void merg_sort_v(std::vector<std::pair<int, int> > &x)
{
	if(x.size() <= 3)
	{
		insertionSort(x);
		return ;
	}
	std::vector<std::pair<int, int> > left, right;
	left = get_part_v(x, 0, 3);
	insertionSort(left);
	right = get_part_v(x, left.size(), x.size() - left.size());
	merg_sort_v(right);
	check_edit_v(x, left, right);
}

std::vector<int> get_JacobsthalSequence_v(int max)
{
	int j = 2;
	std::vector<int> sq;
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

int getIndex_v(std::vector<int> largest, int x)
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
		return (mid + getIndex_v(get_sub_v(largest, mid, largest.size() - 1), x));
	else
		return (getIndex_v(get_sub_v(largest, 0, mid - 1), x));
}

void search_stock_v(std::vector<int> &largest, std::vector<int> lowset, std::vector<int> sq)
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
				index = getIndex_v(largest, lowset[start - 1]);
				largest.insert(largest.begin() + index, lowset[start - 1]);
			}
			start--;
		}
		end = sq[i_sq];
		i_sq++;
	}
}

std::vector<int> sort_v(std::vector<std::pair<int, int> > x)
{
	merg_sort_v(x);

	std::vector<int> largest = make_sequence_v(x, "largest");
	std::vector<int> lowest = make_sequence_v(x, "lowest");
	std::vector<int> sq = get_JacobsthalSequence_v(largest.size() - 1);
	search_stock_v(largest, lowest, sq);
	if(!largest.empty() && largest[0] == -1)
		largest.erase(largest.begin());
	return largest;
}

PmergeMe::PmergeMe(char **arg)
{
	int i = 1;

	while(arg[i])
	{
		v_str.push_back(arg[i]);
		d_str.push_back(arg[i]);
		i++;
	}
}

void PmergeMe::setVector()
{
	this->vc = string_to_int_v(v_str);
}
void PmergeMe::setDeque()
{
	this->dq = string_to_int_d(d_str);
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
	if(ac == 1)
	{
		std::cerr << "no args\n";
		return 1;
	}
	try
	{
		PmergeMe nb(av);
        clock_t start_vector = clock();
		nb.setVector();
        nb.sort(nb.vc);
        double duration_vector = static_cast<double>(clock() - start_vector) / CLOCKS_PER_SEC;
		clock_t start_deque = clock();
		nb.setDeque();
		nb.sort(nb.dq);
        double duration_deque = static_cast<double>(clock() - start_deque) / CLOCKS_PER_SEC;
		std::cout << "Before: ";
		print_str_v(nb.v_str);
		std::cout << "After: ";
		print_int_v(nb.vc);
		std::cout << "Time to process a range of " << nb.vc.size() << " elements with std::vector " <<  duration_vector << " us\n";
		std::cout << "Time to process a range of " << nb.vc.size() << " elements with std::deque " <<  duration_deque << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return 0;
}