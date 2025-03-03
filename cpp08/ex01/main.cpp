#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	std::vector<int> v;
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	sp.addNumbers(v.begin(), v.end(), v.size());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
