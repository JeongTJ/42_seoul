#include "iter.hpp"
#include <iostream>
#include <string>

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
