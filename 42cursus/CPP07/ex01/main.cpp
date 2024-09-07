#include "iter.hpp"
#include <iostream>
#include <string>

void multi_2(int& a) {
	std::cout << a * 2 << std::endl;
}

void power_2(int& a) {
	std::cout << a * a << std::endl;
}

void string_double(std::string& a) {
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a;
	std::cout << std::endl;
}

int main() {
	try {
		int array[10];
		for (int i = 0; i < 10; i++)
			array[i] = i + 1;
		::iter(array, 10, multi_2);
		::iter(array, 10, power_2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::string array[3] = {"apple", "bot", "banana"};
		::iter(array, 3, string_double);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
