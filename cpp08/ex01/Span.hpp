#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
class Span
{
	private:
		std::vector<int> numbers;
		unsigned int n;
	public:
		Span(int n);
		Span();
		Span(const Span &s);
		Span& operator=(const Span &s);
		void addNumber(int numbers);
		void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end, int ss);
		int shortestSpan();
		int longestSpan();
		~Span();
};

#endif
