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

		template <typename T>
		void addNumber(T& container) {
			if (container.size() + data.size() > N)
				throw std::logic_error("container is full");
			for (typename T::iterator it = container.begin(); it != container.end(); it++)
				data.push_back(*it);
		}
	private:
		Span();
		std::vector<unsigned int> data;
		unsigned int N;
};

#endif