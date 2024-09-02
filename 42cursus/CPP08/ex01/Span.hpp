#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	public:
		Span(int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		void addNumber(unsigned int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
	private:
		Span();
		std::vector<unsigned int> data;
		unsigned int N;
};

#endif