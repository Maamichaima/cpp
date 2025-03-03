#include "Span.hpp"

Span::Span(int n)
{
	this->n = n;
	numbers.reserve(n);
}

Span::Span()
{
}

Span::Span(const Span &s)
{
	*this = s;
}

Span &Span::operator=(const Span &s)
{
    if(this != &s)
	{
		this->numbers = s.numbers;
		this->n = s.n;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if(numbers.size() >= this->n)
		throw std::out_of_range("Span is full. Cannot add more numbers.");
	this->numbers.insert(this->numbers.end(), n);
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end, int ss)
{
	if(ss + numbers.size() > n)
		throw std::out_of_range("Span is full. Cannot add more numbers.");
	numbers.insert(numbers.end(), start, end);
}

// add another function for addNumberssssssss

int Span::shortestSpan()
{
	try
	{
		if(numbers.size() < 2)
			throw std::logic_error("Not enough numbers to find a span.");
		std::vector<int>::iterator it;
		std::vector<int>::iterator prev;

		int minSpan = std::numeric_limits<int>::max();
		std::sort(numbers.begin(), numbers.end());
		for(it = numbers.begin() + 1; it != numbers.end(); it++)
		{
			prev = it - 1;
			int span = *it - *prev;
			if(span < minSpan)
				minSpan = span;
		}
		return minSpan;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;//??
}

int Span::longestSpan()
{
	try
	{
		if(numbers.size() < 2)
			throw std::logic_error("Not enough numbers to find a span.");
		std::vector<int>::iterator _max = std::max_element(numbers.begin(), numbers.end());
		std::vector<int>::iterator _min = std::min_element(numbers.begin(), numbers.end());
		return *_max - *_min;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
	
}

Span::~Span()
{

}