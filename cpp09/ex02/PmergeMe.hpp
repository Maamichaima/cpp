#include <iostream>
#include <set>

class PmergeMe
{
	private:
	public:
		std::vector<int> vc;
		std::deque<int> dq;
		PmergeMe();
		// PmergeMe();
		PmergeMe(std::string arg);
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