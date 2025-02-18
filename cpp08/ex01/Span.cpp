#include "Span.hpp"

Span::Span(int n)
{
	
}

void Span::addNumber(int N)
{
	this->N.insert(this->N.end(), N);
	// check ??
}

int Span::shortestSpan()
{
    std::vector<int>::iterator it;
	int min = 200;
	std::sort(N.begin(), N.end());
	std::vector<int>::iterator prev;
    for(it = N.begin() + 1; it != N.end(); it++)
    {
		prev = it - 1;
		int x = *it - *prev;
		if(x < min)
			min = x;
		std::cout << "it -->" << *it << " prev --->" << *prev <<  "\n";
		std::cout << " x --> " << x << " min --> " << min << "\n";
    }
	return min;
}

int Span::longestSpan()
{
	std::vector<int>::iterator _max = std::max_element(N.begin(), N.end());
	std::vector<int>::iterator _min = std::min_element(N.begin(), N.end());

	return *_max - *_min;
}

Span::~Span()
{

}