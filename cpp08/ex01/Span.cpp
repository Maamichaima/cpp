#include "Span.hpp"


Span::Span(int n)
{
	N.insert(N.end(), n);
}

void Span::addNumber(int N)
{
	this->N.insert(this->N.end(), N);
	// check ??
}

int Span::shortestSpan()
{
	std::vector<int>::iterator _max = std::max_element(N.begin(), N.end());
    std::vector<int>::iterator it;
    for(it = N.begin(); it < N.end(); it++)
    {
        if(it)3
    }
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