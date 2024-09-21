#include "RPN.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
	if (argc != 2)
		return 1;
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.run() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
