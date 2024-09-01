#include "Array.hpp"
#include <iostream>

int main() {
	try {
		Array<std::string> array(10);
		Array<std::string> copy_array;

		for (unsigned int i = 0; i < array.size(); i++)
			for (unsigned int j = 0; j <= i; j++)
				array[i] += std::string("*");
		copy_array = array;
		copy_array[5] = "hello";
		for (unsigned int i = 0; i < copy_array.size() + 1; i++)
			std::cout << copy_array[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}