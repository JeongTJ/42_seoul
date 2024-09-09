#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vector;
		std::list<int> list;

		for (int i = 0; i < 100; i++)
			vector.push_back(i * i * i);
		for (int i = 100; i < 200; i++)
			list.push_back(i * i * i * i);
		Span sp = Span(500);
		sp.addNumber(vector);
		sp.addNumber(list);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
