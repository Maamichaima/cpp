#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
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



#endif
