#include "Array.hpp"
#include <iostream>

int main() {
	try {
		Array<std::string> array1(10);
		Array<std::string> array2(5);
		Array<std::string> copy_array;

		for (unsigned int i = 0; i < array1.size(); i++)
			for (unsigned int j = 0; j <= i; j++)
				array1[i] += std::string("*");
		Array<std::string> array3(array1);
		array2 = array1;
		copy_array = array1;
		copy_array[5] = "hello";
		for (unsigned int i = 0; i < copy_array.size(); i++)
			std::cout << copy_array[i] << std::endl;
		for (unsigned int i = 0; i < array2.size(); i++)
			std::cout << array2[i] << std::endl;
		for (unsigned int i = 0; i < array3.size(); i++)
			std::cout << array3[i] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
