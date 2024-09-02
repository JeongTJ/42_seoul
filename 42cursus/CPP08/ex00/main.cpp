#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
	std::vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(7);
	for (int i = 0; i < 10; i++)
		try {
			std::cout << easyfind(v, i) - v.begin() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	return 0;
}