#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vector1;
		std::list<int> list1;

		for (int i = 0; i < 100; i++)
			vector1.push_back(i * i * i);
		for (int i = 100; i < 200; i++)
			list1.push_back(i * i * i * i);
		Span sp = Span(500);
		sp.addNumber(vector1);
		sp.addNumber(list1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
