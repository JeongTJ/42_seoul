#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("tajeong", 42);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++)
				a.increment(2);
			for (int j = 0; j < 10; j++)
				a.decrement(2);
			std::cout << a << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
