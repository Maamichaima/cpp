#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	private:
		std::vector<int> N;
	public:
		Span(int n);
		void addNumber(int N);
		int shortestSpan();
		int longestSpan();
		~Span();
};

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

	return 0;
}

int Span::longestSpan()
{
	return 0;
}

Span::~Span()
{
}


#endif
