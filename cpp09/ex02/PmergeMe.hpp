#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <limits>
#include <iomanip>
#include <cstdlib>
class PmergeMe
{
	public:
		std::vector<int> vc;
		std::deque<int> dq;
		std::vector<std::string> v_str;
		std::deque<std::string> d_str;
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		PmergeMe(char **arg);
		void setVector();
		void setDeque();
		void sort(std::vector<int> vc);
		void sort(std::deque<int> dq);
		~PmergeMe();
};

std::deque<std::string> split_d(const std::string& str, char delimiter);
std::deque<int> string_to_int_d(std::deque<std::string> str);
std::vector<std::pair<int, int> > makePairs_v(std::vector<int> numbers);
std::deque<std::pair<int, int> > makePairs_d(std::deque<int> numbers);
std::deque<int> sort_d(std::deque<std::pair<int, int> > x);
void print_int_d(std::deque<int> x);
int is_valid(std::string c);

#endif